// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate();
	Move();
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent)
		UE_LOG(LogTemp, Warning, TEXT("Input Controller is null. "), *GetOwner()->GetName());

	// Move input
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::CalculateMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::CalculateMoveRight);
	PlayerInputComponent->BindAxis("Rotate", this, &AMyPawn::CalculateRotate);
}

void AMyPawn::CalculateMoveForward(float value)
{
	MoveDirection = FVector(value * MoveSpeed * GetWorld()->DeltaTimeSeconds, MoveDirection.Y, 0.f);
}

void AMyPawn::CalculateMoveRight(float value)
{
	MoveDirection = FVector(MoveDirection.X, value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.f);
}

void AMyPawn::CalculateRotate(float value)
{
	float RotateAmount = value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0, RotateAmount, 0);
	RotationDirection = FQuat(Rotation);
}

void AMyPawn::Move()
{
	AddActorLocalOffset(MoveDirection, true);
}

void AMyPawn::Rotate()
{
	AddActorLocalRotation(RotationDirection, true);
}