// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAI.h"
#include "EnemyAIController.h"


void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{

	AEnemyAI* EnemyAI = Cast<AEnemyAI>(GetPawn());

	
	// AI move between waypoints
	if (EnemyAI)
	{
		EnemyAI->MoveToWaypoints();
		
		if (EnemyAI->SeePlayer)
		{
			
		}
		else
		{
			
		}
		
	}
}