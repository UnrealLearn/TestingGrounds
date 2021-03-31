// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BIGTESTINGGRPROJECT_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

	public:
	TArray<AActor*> GetPatrolPoints() const;

   private: //TODO remove or create getFunction
	   UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		   TArray<AActor*> PatrolingPointsCPP;
		
};
