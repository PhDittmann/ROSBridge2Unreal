// Fill out your copyright notice in the Description page of Project Settings.


#include "ROSMsgQuaternion.h"
#include "DataHelpers.h"

UROSMsgQuaternion* UROSMsgQuaternion::Create(const FQuat& Data)
{
	UROSMsgQuaternion* Message = NewObject<UROSMsgQuaternion>();
	Message->X = Data.X;
	Message->Y = Data.Y;
	Message->Z = Data.Z;
	Message->W = Data.W;
	return Message;
}

UROSMsgQuaternion* UROSMsgQuaternion::CreateEmpty()
{
	return NewObject<UROSMsgQuaternion>();
}

FQuat UROSMsgQuaternion::AsFQuat() const
{
	return FQuat(X,Y,Z,W);
}

void UROSMsgQuaternion::ToData(ROSData& Message) const
{
	DataHelpers::AppendDouble(Message, "x", X);
	DataHelpers::AppendDouble(Message, "y", Y);
	DataHelpers::AppendDouble(Message, "z", Z);
	DataHelpers::AppendDouble(Message, "z", W);
}

bool UROSMsgQuaternion::FromData(const ROSData& Message)
{
	return DataHelpers::ExtractDouble(Message, "x", X)
	&& DataHelpers::ExtractDouble(Message, "y", Y)
	&& DataHelpers::ExtractDouble(Message, "z", Z)
	&& DataHelpers::ExtractDouble(Message, "w", W);
}
