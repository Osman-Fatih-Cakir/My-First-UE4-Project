// Fill out your copyright notice in the Description page of Project Settings.

#include "Waypoint.h"
#include "EnemyAIController.h"
#include "EnemyAI.h"

#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	MoveToWaypoints();
}

// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemyAI::MoveToWaypoints()
{
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController)
	{
		if (CurrentWaypoint <= Waypoints.Num())
		{
			for (AActor* Waypoint : Waypoints) // Iterate trough waypoints
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);
				if (WaypointItr)
				{
					if (WaypointItr->getWaypointOrder() == CurrentWaypoint)
					{
						EnemyAIController->MoveToActor(WaypointItr, 5.f, false);
						CurrentWaypoint = FMath::RandRange(0, MaxWaypoint); // Random next waypoint
						break;
					}
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO ENEMY AI CONTROLLER"));
	}
}

