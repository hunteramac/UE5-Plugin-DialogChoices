#include "AsyncSequence.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"

#include "UObject/ScriptDelegates.h"

#include "LevelSequenceActor.h"

UAsyncSequence::UAsyncSequence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UAsyncSequence* UAsyncSequence::PlayLevelSequence(UObject* InWorldContextObject, ULevelSequence* Sequence)
{
	UAsyncSequence* AsyncPlayer = NewObject<UAsyncSequence>();
	AsyncPlayer->WorldContextObject = InWorldContextObject;
	AsyncPlayer->Sequence = Sequence;
	return AsyncPlayer;
}

void UAsyncSequence::Activate()
{
	//setup sequence player
	ULevelSequencePlayer* LevelSequencePlayer =
		ULevelSequencePlayer::CreateLevelSequencePlayer(
			WorldContextObject,
			Sequence,
			FMovieSceneSequencePlaybackSettings(),
			OutActor
		);

	//Bind callback to player onStop event
	FScriptDelegate SequenceFinCallback;
	SequenceFinCallback.BindUFunction(this, "HandleSequenceCompletion");
	LevelSequencePlayer->OnStop.Add(SequenceFinCallback);


	//Play sequence
	if (LevelSequencePlayer)
	{
		LevelSequencePlayer->Play();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to create level sequence player"));
		HandleSequenceCompletion();
	}

	return;
}

void UAsyncSequence::HandleSequenceCompletion()//int dummy)
{
	Completion.Broadcast();

	SetReadyToDestroy();
}