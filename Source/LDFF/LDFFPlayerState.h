// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "LDFFPlayerState.generated.h"

class ULDFFAttributeSet;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class LDFF_API ALDFFPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ALDFFPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<ULDFFAttributeSet> GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<ULDFFAttributeSet> AttributeSet;
};
