// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
//Appended by me
#include "AIController.h"

//Dont need this anymore
//#include "ThirdPersonCharacterCPP.h"

//We need the component we are using 
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{	
	

	

	//Get Patrol Points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	//Protect Against No PatrolRoute Component
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	//Old way couple 
	//auto PatrolingGuard = Cast<AThirdPersonCharacterCPP>(ControlledPawn);

	//TO DO protect against Empty Patrol Route
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A GUARD IS MISSING PATROL POINTS"));
		return EBTNodeResult::Failed;
	}

	//Set Next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	//TO DO Protect Against EmptyWaypoints

	//BlackboardComp->SetValueAsInt("Index", Index);

	
	
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"),Index);

	return EBTNodeResult::Succeeded;
}
