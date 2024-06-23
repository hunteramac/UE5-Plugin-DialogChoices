// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectDialogLogic.h"

UObjectDialogLogic::UObjectDialogLogic()
{
	currentHightlightedChoice = 0;
	NumChoices = 0;
	newDisplay = true;
}

void UObjectDialogLogic::InitializeObject(int MaxChoices)
{
	NumChoices = MaxChoices;
	newDisplay = true;
}

UObjectDialogLogic::~UObjectDialogLogic()
{
}

int UObjectDialogLogic::GetHighlightIndex() {
	return currentHightlightedChoice;
}

void UObjectDialogLogic::MoveHightlightedChoiceDown() {
	if (newDisplay) {
		newDisplay = false;
		currentHightlightedChoice = 0;
	}
	else 
	{ 
		currentHightlightedChoice = (currentHightlightedChoice + 1) % NumChoices; 
	}
}

void UObjectDialogLogic::MoveHightlightedChoiceUp() {
	if (newDisplay) {
		newDisplay = false;
	}
	else 
	{ 
		currentHightlightedChoice = (currentHightlightedChoice - 1 + NumChoices) % NumChoices; 
	}
}