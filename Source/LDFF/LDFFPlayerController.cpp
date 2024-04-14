// Copyright Epic Games, Inc. All Rights Reserved.

#include "LDFFPlayerController.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "LDFFPlayerState.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ALDFFPlayerController::ALDFFPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

UAbilitySystemComponent* ALDFFPlayerController::GetAbilitySystemComponent() const
{
	return GetPlayerState<ALDFFPlayerState>()->GetAbilitySystemComponent();
}

void ALDFFPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	for (const TSubclassOf<UGameplayAbility> Ability : Abilities)
	{
		GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(Ability));
	}
}
