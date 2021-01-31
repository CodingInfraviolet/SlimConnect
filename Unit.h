#pragma once
#include <string>

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
		PerDegree
	};
private:
	const std::string unitString;

	std::string typeToString(Type type) const
	{
		switch (type)
		{
		case Type::Meter:
			return "meter";
		case Type::Centimeter:
			return "centimeter";
		case Type::Kilometer:
			return "kilometer";
		case Type::Millimeter:
			return "millimeter";
		case Type::Mile:
			return "mile";
		case Type::Decimile:
			return "decimile";
		case Type::NauticalMile:
			return "nautical mile";
		case Type::Decinmile:
			return "decinmile";
		case Type::Foot:
			return "foot";
		case Type::Inch:
			return "inch";
		case Type::Yard:
			return "yard";
		case Type::SquareInch:
			return "square inch";
		case Type::SquareFeet:
			return "square feet";
		case Type::SquareYard:
			return "square yard";
		case Type::SquareMeter:
			return "square meter";
		case Type::SquareCentimeter:
			return "square centimeter";
		case Type::SquareKilometer:
			return "square kilometer";
		case Type::SquareMillimeter:
			return "square millimeter";
		case Type::SquareMile:
			return "square mile";
		case Type::CubicInch:
			return "cubic inch";
		case Type::CubicFoot:
			return "cubic foot";
		case Type::CubicYard:
			return "cubic yard";
		case Type::CubicMile:
			return "cubic mile";
		case Type::CubicMillimeter:
			return "cubic millimeter";
		case Type::CubicCentimeter:
			return "cubic centimeter";
		case Type::MeterCubed:
			return "meter cubed";
		case Type::CubicKilometer:
			return "cubic kilometer";
		case Type::Liter:
			return "liter";
		case Type::Gallon:
			return "gallon";
		case Type::Quart:
			return "quart";
		case Type::Kelvin:
			return "kelvin";
		case Type::Rankine:
			return "rankine";
		case Type::Farenheit:
			return "farenheit";
		case Type::Celsius:
			return "celsius";
		case Type::Radian:
			return "radian";
		case Type::Round:
			return "round";
		case Type::Degree:
			return "degree";
		case Type::DegreeLatitude:
			return "degree latitude";
		case Type::DegreeLongitude:
			return "degree longitude";
		case Type::Grad:
			return "grad";
		case Type::MeterLatitude:
			return "meter latitude";
		case Type::RadianPerSecond:
			return "radian per second";
		case Type::RevolutionPerMinute:
			return "revolution per minute";
		case Type::MinutePerRound:
			return "minute per round";
		case Type::NiceMinutePerRound:
			return "nice minute per round";
		case Type::DegreePerSecond:
			return "degree per second";
		case Type::MeterPerSecond:
			return "meter per second";
		case Type::MeterPerMinute:
			return "meter per minute";
		case Type::FeetPerSecond:
			return "feet/second";
		case Type::FeetPerMinute:
			return "feet/minute";
		case Type::KilometerPerhour:
			return "kilometer/hour";
		case Type::Knot:
			return "knot";
		case Type::MilePerHour:
			return "mile per hour";
		case Type::Mach:
			return "mach";
		case Type::MeterPerSecondSquaredMetersPerSecondSquared:
			return "meter per second squared meters per second squared";
		case Type::Gforce:
			return "Gforce";
		case Type::FeetPerSecondSquared:
			return "feet per second squared";
		case Type::Second:
			return "second";
		case Type::Minute:
			return "minute";
		case Type::Hour:
			return "hour";
		case Type::Day:
			return "day";
		case Type::HourOver10:
			return "hour over 10";
		case Type::Year:
			return "year";
		case Type::Watt:
			return "Watt";
		case Type::FtLbPerSecond:
			return "ft lb per second";
		case Type::VolumeRate:
			return "Volume rate";
		case Type::Details:
			return "Details";
		case Type::MeterCubedPerSecond:
			return "meter cubed per second";
		case Type::GallonPerHour:
			return "gallon per hour";
		case Type::LiterPerHour:
			return "liter per hour";
		case Type::Kilogram:
			return "kilogram";
		case Type::Slug:
			return "slug";
		case Type::Pound:
			return "pound";
		case Type::KilogramPerSecond:
			return "kilogram per second";
		case Type::PoundPerHour:
			return "pound per hour";
		case Type::Ampere:
			return "ampere";
		case Type::Volt:
			return "volt";
		case Type::Hertz:
			return "Hertz";
		case Type::Kilohertz:
			return "Kilohertz";
		case Type::Megahertz:
			return "Megahertz";
		case Type::FrequencyBCD32:
			return "Frequency BCD32";
		case Type::FrequencyBCD16:
			return "Frequency BCD16";
		case Type::FrequencyADFBCD32:
			return "Frequency ADF BCD32";
		case Type::KilogramPerCubicMeter:
			return "kilogram per cubic meter";
		case Type::SlugPerCubicFeet:
			return "Slug per cubic feet";
		case Type::PoundPerGallon:
			return "pound per gallon";
		case Type::Pascal:
			return "pascal";
		case Type::NewtonPerSquareMeter:
			return "Newton per square meter";
		case Type::Kilopascal:
			return "kilopascal";
		case Type::KilogramForcePerSquareCentimeter:
			return "kilogram force per square centimeter";
		case Type::MillimeterOfMercury:
			return "millimeter of mercury";
		case Type::CentimeterOfMercury:
			return "centimeter of mercury";
		case Type::InchOfMercury:
			return "inch of mercury";
		case Type::Atmosphere:
			return "atmosphere";
		case Type::MillimeterOfWater:
			return "millimeter of water";
		case Type::PoundForcePerSquareInch:
			return "pound-force per square inch";
		case Type::PoundForcePerSquareFoot:
			return "pound-force per square foot";
		case Type::Bar:
			return "bar";
		case Type::Millibar:
			return "millibar";
		case Type::BoostCmHg:
			return "boost cmHg";
		case Type::BoostInHg:
			return "boost inHg";
		case Type::BoostPsi:
			return "boost psi";
		case Type::SlugFeetSquared:
			return "slug feet squared";
		case Type::KilogramMeterSquared:
			return "kilogram meter squared";
		case Type::NewtonMeter:
			return "Newton meter";
		case Type::FootPound:
			return "foot-pound";
		case Type::LbfFeet:
			return "lbf-feet";
		case Type::KilogramMeter:
			return "kilogram meter";
		case Type::PoundalFeet:
			return "poundal feet";
		case Type::Part:
			return "part";
		case Type::Half:
			return "half";
		case Type::Third:
			return "third";
		case Type::Percent:
			return "percent";
		case Type::PercentOver100:
			return "percent over 100";
		case Type::Bel:
			return "bel";
		case Type::Decibel:
			return "decibel";
		case Type::MoreThanAHalf:
			return "more_than_a_half";
		case Type::Times:
			return "times";
		case Type::Ratio:
			return "ratio";
		case Type::Number:
			return "number";
		case Type::Scaler:
			return "scaler";
		case Type::Position:
			return "position";
		case Type::Enum:
			return "Enum";
		case Type::Bool:
			return "Bool";
		case Type::Bco16:
			return "Bco16";
		case Type::Mask:
			return "mask";
		case Type::Flags:
			return "flags";
		case Type::String:
			return "string";
		case Type::PerRadian:
			return "per radian";
		case Type::PerDegree:
			return "per degree";
		}
	}
public:

	Unit(Type type) : unitString(typeToString(type)) {}

	static constexpr const char* STRING = "some useful string constant";

	operator const char* () const
	{
		return unitString.c_str();
	}
};
