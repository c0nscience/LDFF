// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFAttributeSet.h"

#include "GameplayEffectExtension.h"

ULDFFAttributeSet::ULDFFAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);

	InitMana(10.f);
	InitMaxMana(50.f);

	InitFollower(1.f);
	InitMaxFollower(10.f);
}

void ULDFFAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	} else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	} else if (Data.EvaluatedData.Attribute == GetFollowerAttribute())
	{
		SetFollower(FMath::Clamp(GetFollower(), 0.f, GetMaxFollower()));
	}
}
