// Fill out your copyright notice in the Description page of Project Settings.


#include "MSSCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMSSCharacter::AMSSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AMSSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMSSCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void AMSSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMSSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMSSCharacter::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

}

