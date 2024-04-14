// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFPlayerState.h"

#include "LDFFAbilitySystemComponent.h"
#include "LDFFAttributeSet.h"

ALDFFPlayerState::ALDFFPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<ULDFFAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<ULDFFAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ALDFFPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
