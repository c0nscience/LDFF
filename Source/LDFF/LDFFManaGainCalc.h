// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "LDFFManaGainCalc.generated.h"

/**
 * 
 */
UCLASS()
class LDFF_API ULDFFManaGainCalc : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	ULDFFManaGainCalc();
	
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
