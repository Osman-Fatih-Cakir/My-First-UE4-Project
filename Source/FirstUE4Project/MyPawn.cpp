// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "GameFramework/Pawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TODO add root component
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
	MoveDirection = GetActorRotation().RotateVector(MoveDirection);
	Move();
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent)
		UE_LOG(LogTemp, Warning, TEXT("Input Controller is null. "));

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
	RotateAmount = value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
}

void AMyPawn::Move()
{
	AddMovementInput(FVector(MoveDirection.X, MoveDirection.Y, 0.f), MoveSpeed, false);
}

void AMyPawn::Rotate()
{
	AddControllerYawInput(RotateAmount);
}

// Increases score
void AMyPawn::AddScore(int value)
{
	score += value;
	UE_LOG(LogTemp, Warning, TEXT("SCORE: %d"), score);
}

// Decrease score
void AMyPawn::DeleteScore(int value)
{
	score -= value;
	UE_LOG(LogTemp, Warning, TEXT("SCORE: %d"), score);
}

// Resets score
void AMyPawn::ResetScore()
{
	score = 0;
	UE_LOG(LogTemp, Warning, TEXT("SCORE: %d"), score);
}
