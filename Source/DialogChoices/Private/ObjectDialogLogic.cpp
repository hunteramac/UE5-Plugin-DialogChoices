// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectDialogLogic.h"

UObjectDialogLogic::UObjectDialogLogic()
{
	currentHightlightedChoice = 0;
	NumChoices = 0;
}

UObjectDialogLogic::~UObjectDialogLogic()
{
}

int UObjectDialogLogic::GetHighlightIndex() {
	return currentHightlightedChoice;
}

void UObjectDialogLogic::MoveHightlightedChoiceDown() {
	++currentHightlightedChoice;
	//wrap around
	if (currentHightlightedChoice > NumChoices) {
		currentHightlightedChoice = 0;
	}
}

void UObjectDialogLogic::MoveHightlightedChoiceUp() {
	--currentHightlightedChoice;
	//wrap around
	if (currentHightlightedChoice < 0) {
		currentHightlightedChoice = NumChoices-1;
	}
}