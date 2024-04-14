// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LDFFAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnded, UGameplayAbility*, GameplayAbility);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivated, UGameplayAbility*, GameplayAbility);

UCLASS()
class LDFF_API ULDFFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	ULDFFAbilitySystemComponent();

	UPROPERTY(BlueprintAssignable, Category="Abilities")
	FOnAbilityEnded OnAbilityEnded_Called;

	UPROPERTY(BlueprintAssignable, Category="Abilities")
	FOnAbilityActivated OnAbilityActivated_Called;
	
	UFUNCTION()
	void OnAbilityEndedCallback(UGameplayAbility* GameplayAbility) const;

	UFUNCTION()
	void OnAbilityActivatedCallback(UGameplayAbility* GameplayAbility) const;
};
