#pragma once
#include <string>
#include <windows.h>
#include "SimConnect.h"
struct TypeInfo {
	const char* name;
	const SIMCONNECT_DATATYPE type;

	TypeInfo(const char* name, SIMCONNECT_DATATYPE type) : name(name), type(type) {}
};

class Unit
{
public:
	enum class Type
	{
		Meter,
		Centimeter,
		Kilometer,
		Millimeter,
		Mile,
		Decimile,
		NauticalMile,
		Decinmile,
		Foot,
		Inch,
		Yard,
		SquareInch,
		SquareFeet,
		SquareYard,
		SquareMeter,
		SquareCentimeter,
		SquareKilometer,
		SquareMillimeter,
		SquareMile,
		CubicInch,
		CubicFoot,
		CubicYard,
		CubicMile,
		CubicMillimeter,
		CubicCentimeter,
		MeterCubed,
		CubicKilometer,
		Liter,
		Gallon,
		Quart,
		Kelvin,
		Rankine,
		Farenheit,
		Celsius,
		Radian,
		Round,
		Degree,
		DegreeLatitude,
		DegreeLongitude,
		Grad,
		MeterLatitude,
		RadianPerSecond,
		RevolutionPerMinute,
		MinutePerRound,
		NiceMinutePerRound,
		DegreePerSecond,
		MeterPerSecond,
		MeterPerMinute,
		FeetPerSecond,
		FeetPerMinute,
		KilometerPerhour,
		Knot,
		MilePerHour,
		Mach,
		MeterPerSecondSquaredMetersPerSecondSquared,
		Gforce,
		FeetPerSecondSquared,
		Second,
		Minute,
		Hour,
		Day,
		HourOver10,
		Year,
		Watt,
		FtLbPerSecond,
		VolumeRate,
		Details,
		MeterCubedPerSecond,
		GallonPerHour,
		LiterPerHour,
		Kilogram,
		Slug,
		Pound,
		KilogramPerSecond,
		PoundPerHour,
		Ampere,
		Volt,
		Hertz,
		Kilohertz,
		Megahertz,
		FrequencyBCD32,
		FrequencyBCD16,
		FrequencyADFBCD32,
		KilogramPerCubicMeter,
		SlugPerCubicFeet,
		PoundPerGallon,
		Pascal,
		NewtonPerSquareMeter,
		Kilopascal,
		KilogramForcePerSquareCentimeter,
		MillimeterOfMercury,
		CentimeterOfMercury,
		InchOfMercury,
		Atmosphere,
		MillimeterOfWater,
		PoundForcePerSquareInch,
		PoundForcePerSquareFoot,
		Bar,
		Millibar,
		BoostCmHg,
		BoostInHg,
		BoostPsi,
		SlugFeetSquared,
		KilogramMeterSquared,
		NewtonMeter,
		FootPound,
		LbfFeet,
		KilogramMeter,
		PoundalFeet,
		Part,
		Half,
		Third,
		Percent,
		PercentOver100,
		Bel,
		Decibel,
		MoreThanAHalf,
		Times,
		Ratio,
		Number,
		Scaler,
		Position,
		Enum,
		Bool,
		Bco16,
		Mask,
		Flags,
		String,
		PerRadian,
		PerDegree,
		Feet
	};
private:
	const TypeInfo typeInfo;

	TypeInfo getTypeInfo(Type type) const
	{
		switch (type)
		{
		case Type::Meter:
			return TypeInfo("meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Centimeter:
			return TypeInfo("centimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Kilometer:
			return TypeInfo("kilometer", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Millimeter:
			return TypeInfo("millimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Mile:
			return TypeInfo("mile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Decimile:
			return TypeInfo("decimile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::NauticalMile:
			return TypeInfo("nautical mile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Decinmile:
			return TypeInfo("decinmile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Foot:
			return TypeInfo("foot", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Inch:
			return TypeInfo("inch", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Yard:
			return TypeInfo("yard", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Feet:
			return TypeInfo("feet", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareInch:
			return TypeInfo("square inch", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareFeet:
			return TypeInfo("square feet", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareYard:
			return TypeInfo("square yard", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareMeter:
			return TypeInfo("square meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareCentimeter:
			return TypeInfo("square centimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareKilometer:
			return TypeInfo("square kilometer", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareMillimeter:
			return TypeInfo("square millimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SquareMile:
			return TypeInfo("square mile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicInch:
			return TypeInfo("cubic inch", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicFoot:
			return TypeInfo("cubic foot", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicYard:
			return TypeInfo("cubic yard", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicMile:
			return TypeInfo("cubic mile", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicMillimeter:
			return TypeInfo("cubic millimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicCentimeter:
			return TypeInfo("cubic centimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterCubed:
			return TypeInfo("meter cubed", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CubicKilometer:
			return TypeInfo("cubic kilometer", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Liter:
			return TypeInfo("liter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Gallon:
			return TypeInfo("gallon", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Quart:
			return TypeInfo("quart", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Kelvin:
			return TypeInfo("kelvin", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Rankine:
			return TypeInfo("rankine", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Farenheit:
			return TypeInfo("farenheit", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Celsius:
			return TypeInfo("celsius", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Radian:
			return TypeInfo("radian", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Round:
			return TypeInfo("round", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Degree:
			return TypeInfo("degree", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::DegreeLatitude:
			return TypeInfo("degree latitude", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::DegreeLongitude:
			return TypeInfo("degree longitude", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Grad:
			return TypeInfo("grad", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterLatitude:
			return TypeInfo("meter latitude", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::RadianPerSecond:
			return TypeInfo("radian per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::RevolutionPerMinute:
			return TypeInfo("revolution per minute", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MinutePerRound:
			return TypeInfo("minute per round", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::NiceMinutePerRound:
			return TypeInfo("nice minute per round", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::DegreePerSecond:
			return TypeInfo("degree per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterPerSecond:
			return TypeInfo("meter per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterPerMinute:
			return TypeInfo("meter per minute", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FeetPerSecond:
			return TypeInfo("feet/second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FeetPerMinute:
			return TypeInfo("feet/minute", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilometerPerhour:
			return TypeInfo("kilometer/hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Knot:
			return TypeInfo("knot", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MilePerHour:
			return TypeInfo("mile per hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Mach:
			return TypeInfo("mach", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterPerSecondSquaredMetersPerSecondSquared:
			return TypeInfo("meters per second squared", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Gforce:
			return TypeInfo("Gforce", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FeetPerSecondSquared:
			return TypeInfo("feet per second squared", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Second:
			return TypeInfo("second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Minute:
			return TypeInfo("minute", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Hour:
			return TypeInfo("hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Day:
			return TypeInfo("day", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::HourOver10:
			return TypeInfo("hour over 10", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Year:
			return TypeInfo("year", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Watt:
			return TypeInfo("Watt", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FtLbPerSecond:
			return TypeInfo("ft lb per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::VolumeRate:
			return TypeInfo("Volume rate", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Details:
			return TypeInfo("Details", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MeterCubedPerSecond:
			return TypeInfo("meter cubed per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::GallonPerHour:
			return TypeInfo("gallon per hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::LiterPerHour:
			return TypeInfo("liter per hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Kilogram:
			return TypeInfo("kilogram", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Slug:
			return TypeInfo("slug", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Pound:
			return TypeInfo("pound", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilogramPerSecond:
			return TypeInfo("kilogram per second", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PoundPerHour:
			return TypeInfo("pound per hour", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Ampere:
			return TypeInfo("ampere", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Volt:
			return TypeInfo("volt", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Hertz:
			return TypeInfo("Hertz", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Kilohertz:
			return TypeInfo("Kilohertz", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Megahertz:
			return TypeInfo("Megahertz", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FrequencyBCD32:
			return TypeInfo("Frequency BCD32", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FrequencyBCD16:
			return TypeInfo("Frequency BCD16", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FrequencyADFBCD32:
			return TypeInfo("Frequency ADF BCD32", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilogramPerCubicMeter:
			return TypeInfo("kilogram per cubic meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SlugPerCubicFeet:
			return TypeInfo("Slug per cubic feet", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PoundPerGallon:
			return TypeInfo("pound per gallon", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Pascal:
			return TypeInfo("pascal", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::NewtonPerSquareMeter:
			return TypeInfo("Newton per square meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Kilopascal:
			return TypeInfo("kilopascal", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilogramForcePerSquareCentimeter:
			return TypeInfo("kilogram force per square centimeter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MillimeterOfMercury:
			return TypeInfo("millimeter of mercury", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::CentimeterOfMercury:
			return TypeInfo("centimeter of mercury", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::InchOfMercury:
			return TypeInfo("inch of mercury", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Atmosphere:
			return TypeInfo("atmosphere", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MillimeterOfWater:
			return TypeInfo("millimeter of water", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PoundForcePerSquareInch:
			return TypeInfo("pound-force per square inch", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PoundForcePerSquareFoot:
			return TypeInfo("pound-force per square foot", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Bar:
			return TypeInfo("bar", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Millibar:
			return TypeInfo("millibar", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::BoostCmHg:
			return TypeInfo("boost cmHg", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::BoostInHg:
			return TypeInfo("boost inHg", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::BoostPsi:
			return TypeInfo("boost psi", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::SlugFeetSquared:
			return TypeInfo("slug feet squared", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilogramMeterSquared:
			return TypeInfo("kilogram meter squared", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::NewtonMeter:
			return TypeInfo("Newton meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::FootPound:
			return TypeInfo("foot-pound", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::LbfFeet:
			return TypeInfo("lbf-feet", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::KilogramMeter:
			return TypeInfo("kilogram meter", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PoundalFeet:
			return TypeInfo("poundal feet", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Part:
			return TypeInfo("part", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Half:
			return TypeInfo("half", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Third:
			return TypeInfo("third", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Percent:
			return TypeInfo("percent", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PercentOver100:
			return TypeInfo("percent over 100", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Bel:
			return TypeInfo("bel", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Decibel:
			return TypeInfo("decibel", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::MoreThanAHalf:
			return TypeInfo("more_than_a_half", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Times:
			return TypeInfo("times", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Ratio:
			return TypeInfo("ratio", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Number:
			return TypeInfo("number", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Scaler:
			return TypeInfo("scaler", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Position:
			return TypeInfo("position", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Enum:
			return TypeInfo("Enum", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Bool:
			return TypeInfo("Bool", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Bco16:
			return TypeInfo("Bco16", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Mask:
			return TypeInfo("mask", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::Flags:
			return TypeInfo("flags", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::String:
			return TypeInfo("string", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PerRadian:
			return TypeInfo("per radian", SIMCONNECT_DATATYPE_FLOAT64);
		case Type::PerDegree:
			return TypeInfo("per degree", SIMCONNECT_DATATYPE_FLOAT64);
		}
	}
public:

	Unit(Type type) : typeInfo(getTypeInfo(type)) {}

	const char* name() const
	{
		return typeInfo.name;
	}

	const SIMCONNECT_DATATYPE type() const {
		return typeInfo.type;
	}
};
