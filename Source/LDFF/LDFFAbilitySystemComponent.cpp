// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFAbilitySystemComponent.h"

ULDFFAbilitySystemComponent::ULDFFAbilitySystemComponent()
{
	AbilityEndedCallbacks.AddUObject(this, &ULDFFAbilitySystemComponent::OnAbilityEndedCallback);
	AbilityActivatedCallbacks.AddUObject(this, &ULDFFAbilitySystemComponent::OnAbilityActivatedCallback);
}

void ULDFFAbilitySystemComponent::OnAbilityEndedCallback(UGameplayAbility* GameplayAbility) const
{
	OnAbilityEnded_Called.Broadcast(GameplayAbility);
}

void ULDFFAbilitySystemComponent::OnAbilityActivatedCallback(UGameplayAbility* GameplayAbility) const
{
	OnAbilityActivated_Called.Broadcast(GameplayAbility);
}
