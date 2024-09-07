// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Start position for object: %s"), *StartLocation.ToString());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	FVector PlatformLocation = GetActorLocation();
	PlatformLocation += PlatformVelocity * DeltaTime;
	SetActorLocation(PlatformLocation);

	Distance = FVector::Dist(StartLocation, PlatformLocation);

	if (Distance >= DesiredDistance || Distance <= -DesiredDistance)
	{
		UE_LOG(LogTemp, Display, TEXT("End position for object: %f"), Distance);
		//Reversing vel
		PlatformVelocity *= -1;
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(PlatformRotation * DeltaTime);
}

