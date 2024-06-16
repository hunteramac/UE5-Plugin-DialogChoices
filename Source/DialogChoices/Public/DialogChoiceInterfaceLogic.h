// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DIALOGCHOICES_API DialogChoiceInterfaceLogic
{
public:
	DialogChoiceInterfaceLogic();
	DialogChoiceInterfaceLogic(int NumberChoices);
	~DialogChoiceInterfaceLogic();

	int GetHighlightIndex();
};
