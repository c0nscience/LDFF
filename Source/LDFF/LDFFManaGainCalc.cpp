// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFManaGainCalc.h"

#include "LDFFAttributeSet.h"

struct LDFFResourceStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Follower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Mana);

	LDFFResourceStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(ULDFFAttributeSet, Follower, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(ULDFFAttributeSet, Mana, Source, true);
	}
};

static const LDFFResourceStatics& ResourceStatics()
{
	static LDFFResourceStatics RStatics;
	return RStatics;
}

ULDFFManaGainCalc::ULDFFManaGainCalc()
{
	RelevantAttributesToCapture.Add(ResourceStatics().FollowerDef);
	RelevantAttributesToCapture.Add(ResourceStatics().ManaDef);
}

void ULDFFManaGainCalc::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	FAggregatorEvaluateParameters EvaluateParameters;

	float Followers = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(ResourceStatics().FollowerDef, EvaluateParameters, Followers);

	UE_LOG(LogTemp, Warning, TEXT("Followers: %f"), Followers);
	if (Followers > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(ResourceStatics().ManaProperty, EGameplayModOp::Additive, Followers));
	}
}


