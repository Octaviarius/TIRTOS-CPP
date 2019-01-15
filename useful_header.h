#ifndef USEFULHEADER_H
#define USEFULHEADER_H


#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <stddef.h>



#define USEFULHEADER_AUTHORS				"Gomanchuk Andrey (Octaviarius)\n"
#define USEFULHEADER_LICENSE				"GNU/GPL v2"

#define USEFULHEADER_VERSION				1.55

/*
    Level1 contains science constants and prefixes
    Level2 advanced consist many unit conversions
        Level3 advanced consist periodic table of chemical elements
*/
#define USEFULHEADER_CONSTANTS_LEVEL		3

/*
    Level1 consists lot of bit operations
*/
#define USEFULHEADER_BITOPS_LEVEL			1

/*
    Level1 consists basic macro declarations and implementation pseudo-language
*/
#define USEFULHEADER_PROPERTIES_LEVEL		1


#define USEFULHEADER_STATEMACHINE_LEVEL		1

/*
    Level1 consists lightweight realization, only hard determine function and methods pointers
    with fixed arguments count
    Level2 consists advanced functional, such as functions and methods  with lesser or equal count of arguments
    TODO: Level3 call functions and methods with other arguments type using function-adapter
*/
#define USEFULHEADER_FUNCTORS_LEVEL			1






//! Something defines for C and C++ variants
#ifdef __cplusplus
    #define EXTERN extern "C"
    #if __cplusplus < 201103L
        #define nullptr NULL
    #endif
#else
    #define EXTERN extern
    #define nullptr NULL
    typedef enum {
        false=0,
        true=1
    } bool;
#endif



#if defined(_MSC_VER) || (__cplusplus > 19980000)
    #define typeof decltype
#endif




//! Check unused 1 variable for warning off
#define UNUSED(x)					(void)(x);
//! Check unused 2 variables for warning off
#define UNUSED2(x0, x1)				(void)(x0); (void)(x1);
//! Check unused 3 variables for warning off
#define UNUSED3(x0, x1, x2)			(void)(x0); (void)(x1); (void)(x2);
//! Check unused 4 variables for warning off
#define UNUSED4(x0, x1, x2, x3)		(void)(x0); (void)(x1); (void)(x2); (void)(x3);
//! Check unused 5 variables for warning off
#define UNUSED5(x0, x1, x2, x3, x4)	(void)(x0); (void)(x1); (void)(x2); (void)(x3); (void)(x4);



//! Return offset address after ident position
#define offsetafter(type, ident)	(offsetof(type, ident) + sizeof(((type*)0)->ident))

//! Return pointer to parent type through pointer on child field
#define baseptr(base_type, member, member_ptr)	( (base_type*)((size_t)member_ptr - offsetof(base_type, member)) )

//! Return elements count of static array
#define countof(stat_array)		( sizeof(stat_array) / sizeof(*stat_array) )

//! Return optimal architecture chars count from input bytes count
#define leastsize(count)		( (count + ((CHAR_BIT/8) - 1)) / (CHAR_BIT/8) )

//! Char size in bytes
#define CHAR_SIZE               (CHAR_BIT/8)

//! Alias var naming and access
#define ALIAS_VAR(alias, target_var)	typeof(target_var) & alias = target_var

































//======================/ Useful science constants /==============================
#if USEFULHEADER_CONSTANTS_LEVEL >= 1
    //--------------константы-------------
    #define SCI_PI				3.141592653589790e+0	//!< П-number
    #define SCI_EXP				2.718281828459050e+0	//!< E-number
    #define SCI_GOLDSECT0		0.618033988749890e+0	//!< gold section 1
    #define SCI_GOLDSECT1		1.618033988749890e+0	//!< gold section 2

    #define SCI_LN2				0.693147180559945e+0   	//!< ln(2)
    #define SCI_LN5 			1.609437912434100e+0   	//!< ln(5)
    #define SCI_LN8				2.079441541679840e+0 	//!< ln(8)
    #define SCI_LN10			2.302585092994050e+0   	//!< ln(10)
    #define SCI_LN16			2.772588722239780e+0  	//!< ln(16)

    #define SCI_LIGHT			0.299792458000000e+9	//!< light velocity in vacuum
    #define SCI_GRAVITY			6.673848000000000e-11 	//!< gravity constant
    #define SCI_GRAVITY_RADIUS(mass)    ((mass)*(2.0*SCI_GRAVITY/(SCI_LIGHT*SCI_LIGHT)))    //!< gravity radius
    #define SCI_PLANCK			6.626069572900000e-34 	//!< Planck constant
    #define SCI_PLANCK_LEN      1.616229380000000e-35 	//!< Planck length constant
    #define SCI_PLANCK_MASS		2.176470510000000e-8 	//!< Planck mass constant
    #define SCI_PLANCK_TIME		5.391161300000000e-44 	//!< Planck time constant
    #define SCI_PLANCK_TEMP		1.416808330000000e-32 	//!< Planck temperature constant
    #define SCI_DIRAC			1.054571800130000e-34 	//!< Dirac constant
    #define SCI_RIEDBERG		1.097373156853955e+7	//!< Riedberg constant

    #define SCI_CHARGE 			1.602176565350000e-19 	//!< elementary change
    #define SCI_E_VACUUM		8.854187820000000e-12 	//!< electricuty constant
    #define SCI_M_VACUUM		1.256637060000000e-6 	//!< magnity constant
    #define SCI_VAC_IMPEDANCE           3.767303134617700e+2	//!< wave resistance of vacuum

    #define SCI_BOLCMAN 		1.380648813000000e-23	//!< Bolcman constant
    #define SCI_AVOGADRO		6.022141292700000e+23	//!< Avogadro constant
    #define SCI_GAS_CONST		8.314462227484500e+0 	//!< gas constant
    #define SCI_FARADEY                 9.648533652390500e+4 	//!< Faradey constant

    #define SCI_B_MAGNETON		9.274009152300000e-24   //!< magneton of Bohr
    #define SCI_N_MAGNETON		5.050783241300000e-27   //!< nuclear magneton
    #define SCI_RADIUSBOHR		0.529177208593600e-10   //!< Bohr radius

    #define SCI_MASS_PROTON		1.672621777000000e-27  	//!< proton mass
    #define SCI_MASS_NEUTRON            1.674927351000000e-27  	//!< neutron mass
    #define SCI_MASS_ELECTRON           9.109382910000000e-31  	//!< electron mass
    #define SCI_AMU 			1.660540210000000e-27  	//!< atomic unit mass

    #define SCI_SUN_MASS		1.989000000000000e+30	//!< Sun mass
    #define SCI_SUN_ACCEL		2.731000000000000e+2	//!< Sun standart acceleration
    #define SCI_MERCURY_MASS		0.328680000000000e+24	//!< Mercury mass
    #define SCI_MERCURY_ACCEL		3.700000000000000e+0	//!< Mercury standart acceleration
    #define SCI_VENUS_MASS		0.328680000000000e+24	//!< Venus mass
    #define SCI_VENUS_ACCEL		8.880000000000000e+0	//!< Venus standart acceleration
    #define SCI_EARTH_MASS		5.976000000000000e+24	//!< Earth mass
    #define SCI_EARTH_ACCEL		9.806605000000000e+0	//!< Earth standart acceleration
    #define SCI_MARS_MASS		0.633450000000000e+24	//!< Mars mass
    #define SCI_MARS_ACCEL		3.860000000000000e+0	//!< Mars standart acceleration
    #define SCI_JUPITER_MASS		1.876643280000000e+27	//!< Jupiter mass
    #define SCI_JUPITER_ACCEL		2.395000000000000e+1	//!< Jupiter standart acceleration
    #define SCI_SATURN_MASS		5.618037600000000e+26	//!< Saturn mass
    #define SCI_SATURN_ACCEL		1.044000000000000e+1	//!< Saturn standart acceleration
    #define SCI_URAN_MASS		8.605440000000000e+25	//!< Uran mass
    #define SCI_URAN_ACCEL		8.860000000000000e+0	//!< Uran standart acceleration
    #define SCI_NEPTUN_MASS		1.015920000000000e+26	//!< Neptun mass
    #define SCI_NEPTUN_ACCEL		1.109000000000000e+1	//!< Neptun standart acceleration
    #define SCI_PLUTO_MASS		1.303000000000000e+22	//!< Pluto mass
    #define SCI_PLUTO_ACCEL		0.617000000000000e+0	//!< Pluto standart acceleration
    #define SCI_MOON_MASS		7.347700000000000e+22	//!< Moon mass
    #define SCI_MOON_ACCEL		1.620000000000000e+0	//!< Moon standart acceleration

    #define DEGREE			1.745329251994330e-2		//!< degrees to radians
    #define GRAD			1.570796326794900e-2   		//!< grads to radians
    #define RAD				1.000000000000000e+0   		//!< radians to radians

    #define PROCENT			0.01						//!< procents to relative value
    #define PROMILLE        0.001						//!< promille to relative value

    #define CELSIUM_KELVIN(t)		((t) + 273.15)   		//!< Celsium to Kelvin
    #define KELVIN_CELSIUM(t)		((t) - 273.15)   		//!< Kelvin to Celsium

    #define FAHRENHEIT_KELVIN(t)	(((t) + 459.67)*0.555555555555556) 	//!< Fahrenheit to Kelvin
    #define KELVIN_FAHRENHEIT(t)	(1.8*(t) - 459.67)   				//!< Kelvin to Fahrenheit


    //-------------- Prefixes of units -------------
    #define _Yotta			(1.0e+24)					//!< yotta
    #define _Zetta			(1.0e+21)					//!< zetta
    #define _Exa			(1.0e+18)					//!< exa
    #define _Peta			(1.0e+15)					//!< peta
    #define _Tera			(1.0e+12)					//!< tera
    #define _Giga			(1.0e+9)					//!< giga
    #define _Mega			(1.0e+6)					//!< mega
    #define _kilo			(1.0e+3)					//!< kilo
    #define _hecto			(1.0e+2)					//!< hecto
    #define _deca			(1.0e+1)					//!< deca

    #define _deci			(1.0e-1)					//!< deci
    #define _centi			(1.0e-2)					//!< centi
    #define _milli			(1.0e-3)					//!< milli
    #define _micro			(1.0e-6)					//!< micro
    #define _nano			(1.0e-9)					//!< nano
    #define _pico			(1.0e-12)					//!< pico
    #define _femto			(1.0e-15)					//!< femto
    #define _atto			(1.0e-18)					//!< atto
    #define _zepto			(1.0e-21)					//!< zepto
    #define _yocto			(1.0e-24)					//!< yocto

    #define _KiB			(1UL<<10)					//! Kibibyte
    #define _MiB			(1UL<<20)					//! Mebibyte
    #define _GiB			(1UL<<30)					//! Gibibyte
    #define _TiB			(1U<<40)					//! Tebibyte
    #define _PiB			(1U<<50)					//! Pebibyte
    #define _EiB			(1U<<60)					//! Exbibyte
    #define _ZiB			(1180591620717411303424)                        //! Zebibyte
    #define _YiB			(1208925819614629174706176)                     //! Yobibyte




#if USEFULHEADER_CONSTANTS_LEVEL >= 2
    //---------- Gramms of mass units (g / unit)------------
    #define MASS_GRAMM				1.0
    #define MASS_CARATO				0.2

    #define MASS_US_STONE			6350.29318
    #define MASS_US_POUND			453.59237
    #define MASS_US_UNCIA			28.349523125
    #define MASS_US_DRAHMA			1.7718451953125
    #define MASS_US_GRAN			0.06479891

    #define MASS_UK_TROYES_UNCIA	31.1034768
    #define MASS_UK_DRAHMA			3.8879346
    #define MASS_UK_SCRUPULUS		1.2959782

    #define MASS_RU_BERKOVEC		164000.0
    #define MASS_RU_PUD				16380.4815
    #define MASS_RU_POUND			409.5120375
    #define MASS_RU_LOT				12.7972511913953
    #define MASS_RU_ZOLOTNIK		4.26575417
    #define MASS_RU_DOLIA			0.044435

    #define MASS_EU_ASA				0.048063
    #define MASS_EU_MARCA			249.0
    #define MASS_EU_TOD				5443.10844
    #define MASS_EU_FIRKIN			29029.91168
    #define MASS_EU_HUNDREDWEIGHT	50802.34544
    #define MASS_EU_HOGSHEAD		453600.0



    //---------- Meters of length units (m / unit)------------
    #define LEN_METER				1.0
    #define LEN_UK_LIGA				4828.032
    #define LEN_UK_MILE				1609.344
    #define LEN_UK_FURHLONG			201.16
    #define LEN_UK_CHAIN			20.1168
    #define LEN_UK_ROD				5.0292
    #define LEN_UK_YARD				0.9144
    #define LEN_UK_FOOT				0.3048
    #define LEN_UK_LINK				0.201168
    #define LEN_UK_HAND				0.1016
    #define LEN_UK_INCH				0.0254
    #define LEN_UK_FOOT				0.3048

    #define LEN_RU_PIAD				0.1778
    #define LEN_RU_STOPA			0.3556
    #define LEN_RU_LOKOT			0.5334
    #define LEN_RU_ARSHIN			0.7112
    #define LEN_RU_SHAG				0.889
    #define LEN_RU_LOB				1.2446
    #define LEN_RU_STOLBEC			1.4224
    #define LEN_RU_POSOH			1.6002
    #define LEN_RU_SAZHEN			2.1336
    #define LEN_RU_KRUG				2.8448
    #define LEN_RU_PIAST			0.0889
    #define LEN_RU_VERSHOK			0.04445
    #define LEN_RU_NOKOT			0.0111125
    #define LEN_RU_LINIA			0.00069453
    #define LEN_RU_VOLOS			0.0000434
    #define LEN_RU_VOLOSOK			0.0000027
    #define LEN_RU_VERSTA			1066.8
    #define LEN_RU_VERSTA_STOLB		1517.41632
    #define LEN_RU_VERSTA_MERNAIA	2133.6
    #define LEN_RU_MILIA			7467.6

    #define LEN_JP_MO				0.00003030303
    #define LEN_JP_RIN				0.0003030303
    #define LEN_JP_BU				0.003030303
    #define LEN_JP_SUN				0.03030303
    #define LEN_JP_SIAKU			0.3030303
    #define LEN_JP_KEN				1.818182
    #define LEN_JP_DJO				3.030303
    #define LEN_JP_TE				109.0909
    #define LEN_JP_RI				3927.273


    //---------- Seconds of timeperiods (s / unit)------------
    #define TIM_SECOND				1.0
    #define TIM_MINUTE				60.0
    #define TIM_HOUR				3600.0
    #define TIM_DAY					86400.0
    #define TIM_WEEK				604800.0
    #define TIM_ACADEMIC_HOUR		2700.0
    #define TIM_TERCIA				0.0166666666666667

#endif//level 2



#if USEFULHEADER_CONSTANTS_LEVEL >= 3

    //! Element name
    #define CHEMTABLE_NAME(el)      CHEMTABLE_##el##_NAME
    //! Element atomic mass unit
    #define CHEMTABLE_AMU(el)       CHEMTABLE_##el##_AMU
    //! Element charge or serial number
    #define CHEMTABLE_Z(el)         CHEMTABLE_##el##_Z
    //! Element count of neutrons
    #define CHEMTABLE_N(el)         CHEMTABLE_##el##_N
    //! Element energy of ionization
    #define CHEMTABLE_ION(el)       CHEMTABLE_##el##_ION
    //! Element density by normal conditions
    #define CHEMTABLE_DENS(el)      CHEMTABLE_##el##_DENS

    #define CHEMTABLE_H_NAME	"Hydrogen"
    #define CHEMTABLE_H_AMU	1.008
    #define CHEMTABLE_H_Z	1
    #define CHEMTABLE_H_N	0
    #define CHEMTABLE_H_ION	13.6
    #define CHEMTABLE_H_DENS	0.09
    #define CHEMTABLE_He_NAME	"Helium"
    #define CHEMTABLE_He_AMU	4.003
    #define CHEMTABLE_He_Z	2
    #define CHEMTABLE_He_N	2
    #define CHEMTABLE_He_ION	24.59
    #define CHEMTABLE_He_DENS	0.18
    #define CHEMTABLE_Li_NAME	"Lithium"
    #define CHEMTABLE_Li_AMU	6.941
    #define CHEMTABLE_Li_Z	3
    #define CHEMTABLE_Li_N	4
    #define CHEMTABLE_Li_ION	5.39
    #define CHEMTABLE_Li_DENS	0.53
    #define CHEMTABLE_Be_NAME	"Beryllium"
    #define CHEMTABLE_Be_AMU	9.012
    #define CHEMTABLE_Be_Z	4
    #define CHEMTABLE_Be_N	5
    #define CHEMTABLE_Be_ION	9.32
    #define CHEMTABLE_Be_DENS	1.85
    #define CHEMTABLE_B_NAME	"Boron"
    #define CHEMTABLE_B_AMU	10.811
    #define CHEMTABLE_B_Z	5
    #define CHEMTABLE_B_N	6
    #define CHEMTABLE_B_ION	8.3
    #define CHEMTABLE_B_DENS	2.34
    #define CHEMTABLE_C_NAME	"Carbon"
    #define CHEMTABLE_C_AMU	12.011
    #define CHEMTABLE_C_Z	6
    #define CHEMTABLE_C_N	6
    #define CHEMTABLE_C_ION	11.26
    #define CHEMTABLE_C_DENS	2.26
    #define CHEMTABLE_N_NAME	"Nitrogen"
    #define CHEMTABLE_N_AMU	14.007
    #define CHEMTABLE_N_Z	7
    #define CHEMTABLE_N_N	7
    #define CHEMTABLE_N_ION	14.53
    #define CHEMTABLE_N_DENS	1.25
    #define CHEMTABLE_O_NAME	"Oxygen"
    #define CHEMTABLE_O_AMU	15.999
    #define CHEMTABLE_O_Z	8
    #define CHEMTABLE_O_N	8
    #define CHEMTABLE_O_ION	13.62
    #define CHEMTABLE_O_DENS	1.43
    #define CHEMTABLE_F_NAME	"Fluorine"
    #define CHEMTABLE_F_AMU	18.998
    #define CHEMTABLE_F_Z	9
    #define CHEMTABLE_F_N	10
    #define CHEMTABLE_F_ION	17.42
    #define CHEMTABLE_F_DENS	1.7
    #define CHEMTABLE_Ne_NAME	"Neon"
    #define CHEMTABLE_Ne_AMU	20.18
    #define CHEMTABLE_Ne_Z	10
    #define CHEMTABLE_Ne_N	10
    #define CHEMTABLE_Ne_ION	21.56
    #define CHEMTABLE_Ne_DENS	0.9
    #define CHEMTABLE_Na_NAME	"Sodium"
    #define CHEMTABLE_Na_AMU	22.99
    #define CHEMTABLE_Na_Z	11
    #define CHEMTABLE_Na_N	12
    #define CHEMTABLE_Na_ION	5.14
    #define CHEMTABLE_Na_DENS	0.97
    #define CHEMTABLE_Mg_NAME	"Magnesium"
    #define CHEMTABLE_Mg_AMU	24.305
    #define CHEMTABLE_Mg_Z	12
    #define CHEMTABLE_Mg_N	12
    #define CHEMTABLE_Mg_ION	7.65
    #define CHEMTABLE_Mg_DENS	1.74
    #define CHEMTABLE_Al_NAME	"Aluminum"
    #define CHEMTABLE_Al_AMU	26.982
    #define CHEMTABLE_Al_Z	13
    #define CHEMTABLE_Al_N	14
    #define CHEMTABLE_Al_ION	5.99
    #define CHEMTABLE_Al_DENS	2.7
    #define CHEMTABLE_Si_NAME	"Silicon"
    #define CHEMTABLE_Si_AMU	28.086
    #define CHEMTABLE_Si_Z	14
    #define CHEMTABLE_Si_N	14
    #define CHEMTABLE_Si_ION	8.15
    #define CHEMTABLE_Si_DENS	2.33
    #define CHEMTABLE_P_NAME	"Phosphorus"
    #define CHEMTABLE_P_AMU	30.974
    #define CHEMTABLE_P_Z	15
    #define CHEMTABLE_P_N	16
    #define CHEMTABLE_P_ION	10.49
    #define CHEMTABLE_P_DENS	1.82
    #define CHEMTABLE_S_NAME	"Sulfur"
    #define CHEMTABLE_S_AMU	32.065
    #define CHEMTABLE_S_Z	16
    #define CHEMTABLE_S_N	16
    #define CHEMTABLE_S_ION	10.36
    #define CHEMTABLE_S_DENS	2.07
    #define CHEMTABLE_Cl_NAME	"Chlorine"
    #define CHEMTABLE_Cl_AMU	35.453
    #define CHEMTABLE_Cl_Z	17
    #define CHEMTABLE_Cl_N	18
    #define CHEMTABLE_Cl_ION	12.97
    #define CHEMTABLE_Cl_DENS	3.21
    #define CHEMTABLE_Ar_NAME	"Argon"
    #define CHEMTABLE_Ar_AMU	39.948
    #define CHEMTABLE_Ar_Z	18
    #define CHEMTABLE_Ar_N	22
    #define CHEMTABLE_Ar_ION	15.76
    #define CHEMTABLE_Ar_DENS	1.78
    #define CHEMTABLE_K_NAME	"Potassium"
    #define CHEMTABLE_K_AMU	39.098
    #define CHEMTABLE_K_Z	19
    #define CHEMTABLE_K_N	20
    #define CHEMTABLE_K_ION	4.34
    #define CHEMTABLE_K_DENS	0.86
    #define CHEMTABLE_Ca_NAME	"Calcium"
    #define CHEMTABLE_Ca_AMU	40.078
    #define CHEMTABLE_Ca_Z	20
    #define CHEMTABLE_Ca_N	20
    #define CHEMTABLE_Ca_ION	6.11
    #define CHEMTABLE_Ca_DENS	1.55
    #define CHEMTABLE_Sc_NAME	"Scandium"
    #define CHEMTABLE_Sc_AMU	44.956
    #define CHEMTABLE_Sc_Z	21
    #define CHEMTABLE_Sc_N	24
    #define CHEMTABLE_Sc_ION	6.56
    #define CHEMTABLE_Sc_DENS	2.99
    #define CHEMTABLE_Ti_NAME	"Titanium"
    #define CHEMTABLE_Ti_AMU	47.867
    #define CHEMTABLE_Ti_Z	22
    #define CHEMTABLE_Ti_N	26
    #define CHEMTABLE_Ti_ION	6.83
    #define CHEMTABLE_Ti_DENS	4.54
    #define CHEMTABLE_V_NAME	"Vanadium"
    #define CHEMTABLE_V_AMU	50.942
    #define CHEMTABLE_V_Z	23
    #define CHEMTABLE_V_N	28
    #define CHEMTABLE_V_ION	6.75
    #define CHEMTABLE_V_DENS	6.11
    #define CHEMTABLE_Cr_NAME	"Chromium"
    #define CHEMTABLE_Cr_AMU	51.996
    #define CHEMTABLE_Cr_Z	24
    #define CHEMTABLE_Cr_N	28
    #define CHEMTABLE_Cr_ION	6.77
    #define CHEMTABLE_Cr_DENS	7.19
    #define CHEMTABLE_Mn_NAME	"Manganese"
    #define CHEMTABLE_Mn_AMU	54.938
    #define CHEMTABLE_Mn_Z	25
    #define CHEMTABLE_Mn_N	30
    #define CHEMTABLE_Mn_ION	7.43
    #define CHEMTABLE_Mn_DENS	7.43
    #define CHEMTABLE_Fe_NAME	"Iron"
    #define CHEMTABLE_Fe_AMU	55.845
    #define CHEMTABLE_Fe_Z	26
    #define CHEMTABLE_Fe_N	30
    #define CHEMTABLE_Fe_ION	7.9
    #define CHEMTABLE_Fe_DENS	7.87
    #define CHEMTABLE_Co_NAME	"Cobalt"
    #define CHEMTABLE_Co_AMU	58.933
    #define CHEMTABLE_Co_Z	27
    #define CHEMTABLE_Co_N	32
    #define CHEMTABLE_Co_ION	7.88
    #define CHEMTABLE_Co_DENS	8.9
    #define CHEMTABLE_Ni_NAME	"Nickel"
    #define CHEMTABLE_Ni_AMU	58.693
    #define CHEMTABLE_Ni_Z	28
    #define CHEMTABLE_Ni_N	31
    #define CHEMTABLE_Ni_ION	7.64
    #define CHEMTABLE_Ni_DENS	8.9
    #define CHEMTABLE_Cu_NAME	"Copper"
    #define CHEMTABLE_Cu_AMU	63.546
    #define CHEMTABLE_Cu_Z	29
    #define CHEMTABLE_Cu_N	35
    #define CHEMTABLE_Cu_ION	7.73
    #define CHEMTABLE_Cu_DENS	8.96
    #define CHEMTABLE_Zn_NAME	"Zinc"
    #define CHEMTABLE_Zn_AMU	65.39
    #define CHEMTABLE_Zn_Z	30
    #define CHEMTABLE_Zn_N	35
    #define CHEMTABLE_Zn_ION	9.39
    #define CHEMTABLE_Zn_DENS	7.13
    #define CHEMTABLE_Ga_NAME	"Gallium"
    #define CHEMTABLE_Ga_AMU	69.723
    #define CHEMTABLE_Ga_Z	31
    #define CHEMTABLE_Ga_N	39
    #define CHEMTABLE_Ga_ION	6
    #define CHEMTABLE_Ga_DENS	5.91
    #define CHEMTABLE_Ge_NAME	"Germanium"
    #define CHEMTABLE_Ge_AMU	72.64
    #define CHEMTABLE_Ge_Z	32
    #define CHEMTABLE_Ge_N	41
    #define CHEMTABLE_Ge_ION	7.9
    #define CHEMTABLE_Ge_DENS	5.32
    #define CHEMTABLE_As_NAME	"Arsenic"
    #define CHEMTABLE_As_AMU	74.922
    #define CHEMTABLE_As_Z	33
    #define CHEMTABLE_As_N	42
    #define CHEMTABLE_As_ION	9.79
    #define CHEMTABLE_As_DENS	5.72
    #define CHEMTABLE_Se_NAME	"Selenium"
    #define CHEMTABLE_Se_AMU	78.96
    #define CHEMTABLE_Se_Z	34
    #define CHEMTABLE_Se_N	45
    #define CHEMTABLE_Se_ION	9.75
    #define CHEMTABLE_Se_DENS	4.79
    #define CHEMTABLE_Br_NAME	"Bromine"
    #define CHEMTABLE_Br_AMU	79.904
    #define CHEMTABLE_Br_Z	35
    #define CHEMTABLE_Br_N	45
    #define CHEMTABLE_Br_ION	11.81
    #define CHEMTABLE_Br_DENS	3.12
    #define CHEMTABLE_Kr_NAME	"Krypton"
    #define CHEMTABLE_Kr_AMU	83.8
    #define CHEMTABLE_Kr_Z	36
    #define CHEMTABLE_Kr_N	48
    #define CHEMTABLE_Kr_ION	14
    #define CHEMTABLE_Kr_DENS	3.75
    #define CHEMTABLE_Rb_NAME	"Rubidium"
    #define CHEMTABLE_Rb_AMU	85.468
    #define CHEMTABLE_Rb_Z	37
    #define CHEMTABLE_Rb_N	48
    #define CHEMTABLE_Rb_ION	4.18
    #define CHEMTABLE_Rb_DENS	1.63
    #define CHEMTABLE_Sr_NAME	"Strontium"
    #define CHEMTABLE_Sr_AMU	87.62
    #define CHEMTABLE_Sr_Z	38
    #define CHEMTABLE_Sr_N	50
    #define CHEMTABLE_Sr_ION	5.69
    #define CHEMTABLE_Sr_DENS	2.54
    #define CHEMTABLE_Y_NAME	"Yttrium"
    #define CHEMTABLE_Y_AMU	88.906
    #define CHEMTABLE_Y_Z	39
    #define CHEMTABLE_Y_N	50
    #define CHEMTABLE_Y_ION	6.22
    #define CHEMTABLE_Y_DENS	4.47
    #define CHEMTABLE_Zr_NAME	"Zirconium"
    #define CHEMTABLE_Zr_AMU	91.224
    #define CHEMTABLE_Zr_Z	40
    #define CHEMTABLE_Zr_N	51
    #define CHEMTABLE_Zr_ION	6.63
    #define CHEMTABLE_Zr_DENS	6.51
    #define CHEMTABLE_Nb_NAME	"Niobium"
    #define CHEMTABLE_Nb_AMU	92.906
    #define CHEMTABLE_Nb_Z	41
    #define CHEMTABLE_Nb_N	52
    #define CHEMTABLE_Nb_ION	6.76
    #define CHEMTABLE_Nb_DENS	8.57
    #define CHEMTABLE_Mo_NAME	"Molybdenum"
    #define CHEMTABLE_Mo_AMU	95.94
    #define CHEMTABLE_Mo_Z	42
    #define CHEMTABLE_Mo_N	54
    #define CHEMTABLE_Mo_ION	7.09
    #define CHEMTABLE_Mo_DENS	10.22
    #define CHEMTABLE_Tc_NAME	"Technetium"
    #define CHEMTABLE_Tc_AMU	98
    #define CHEMTABLE_Tc_Z	43
    #define CHEMTABLE_Tc_N	55
    #define CHEMTABLE_Tc_ION	7.28
    #define CHEMTABLE_Tc_DENS	11.5
    #define CHEMTABLE_Ru_NAME	"Ruthenium"
    #define CHEMTABLE_Ru_AMU	101.07
    #define CHEMTABLE_Ru_Z	44
    #define CHEMTABLE_Ru_N	57
    #define CHEMTABLE_Ru_ION	7.36
    #define CHEMTABLE_Ru_DENS	12.37
    #define CHEMTABLE_Rh_NAME	"Rhodium"
    #define CHEMTABLE_Rh_AMU	102.906
    #define CHEMTABLE_Rh_Z	45
    #define CHEMTABLE_Rh_N	58
    #define CHEMTABLE_Rh_ION	7.46
    #define CHEMTABLE_Rh_DENS	12.41
    #define CHEMTABLE_Pd_NAME	"Palladium"
    #define CHEMTABLE_Pd_AMU	106.42
    #define CHEMTABLE_Pd_Z	46
    #define CHEMTABLE_Pd_N	60
    #define CHEMTABLE_Pd_ION	8.34
    #define CHEMTABLE_Pd_DENS	12.02
    #define CHEMTABLE_Ag_NAME	"Silver"
    #define CHEMTABLE_Ag_AMU	107.868
    #define CHEMTABLE_Ag_Z	47
    #define CHEMTABLE_Ag_N	61
    #define CHEMTABLE_Ag_ION	7.58
    #define CHEMTABLE_Ag_DENS	10.5
    #define CHEMTABLE_Cd_NAME	"Cadmium"
    #define CHEMTABLE_Cd_AMU	112.411
    #define CHEMTABLE_Cd_Z	48
    #define CHEMTABLE_Cd_N	64
    #define CHEMTABLE_Cd_ION	8.99
    #define CHEMTABLE_Cd_DENS	8.65
    #define CHEMTABLE_In_NAME	"Indium"
    #define CHEMTABLE_In_AMU	114.818
    #define CHEMTABLE_In_Z	49
    #define CHEMTABLE_In_N	66
    #define CHEMTABLE_In_ION	5.79
    #define CHEMTABLE_In_DENS	7.31
    #define CHEMTABLE_Sn_NAME	"Tin"
    #define CHEMTABLE_Sn_AMU	118.71
    #define CHEMTABLE_Sn_Z	50
    #define CHEMTABLE_Sn_N	69
    #define CHEMTABLE_Sn_ION	7.34
    #define CHEMTABLE_Sn_DENS	7.31
    #define CHEMTABLE_Sb_NAME	"Antimony"
    #define CHEMTABLE_Sb_AMU	121.76
    #define CHEMTABLE_Sb_Z	51
    #define CHEMTABLE_Sb_N	71
    #define CHEMTABLE_Sb_ION	8.61
    #define CHEMTABLE_Sb_DENS	6.68
    #define CHEMTABLE_Te_NAME	"Tellurium"
    #define CHEMTABLE_Te_AMU	127.6
    #define CHEMTABLE_Te_Z	52
    #define CHEMTABLE_Te_N	76
    #define CHEMTABLE_Te_ION	9.01
    #define CHEMTABLE_Te_DENS	6.24
    #define CHEMTABLE_I_NAME	"Iodine"
    #define CHEMTABLE_I_AMU	126.905
    #define CHEMTABLE_I_Z	53
    #define CHEMTABLE_I_N	74
    #define CHEMTABLE_I_ION	10.45
    #define CHEMTABLE_I_DENS	4.93
    #define CHEMTABLE_Xe_NAME	"Xenon"
    #define CHEMTABLE_Xe_AMU	131.293
    #define CHEMTABLE_Xe_Z	54
    #define CHEMTABLE_Xe_N	77
    #define CHEMTABLE_Xe_ION	12.13
    #define CHEMTABLE_Xe_DENS	5.9
    #define CHEMTABLE_Cs_NAME	"Cesium"
    #define CHEMTABLE_Cs_AMU	132.906
    #define CHEMTABLE_Cs_Z	55
    #define CHEMTABLE_Cs_N	78
    #define CHEMTABLE_Cs_ION	3.89
    #define CHEMTABLE_Cs_DENS	1.87
    #define CHEMTABLE_Ba_NAME	"Barium"
    #define CHEMTABLE_Ba_AMU	137.327
    #define CHEMTABLE_Ba_Z	56
    #define CHEMTABLE_Ba_N	81
    #define CHEMTABLE_Ba_ION	5.21
    #define CHEMTABLE_Ba_DENS	3.59
    #define CHEMTABLE_La_NAME	"Lanthanum"
    #define CHEMTABLE_La_AMU	138.906
    #define CHEMTABLE_La_Z	57
    #define CHEMTABLE_La_N	82
    #define CHEMTABLE_La_ION	5.58
    #define CHEMTABLE_La_DENS	6.15
    #define CHEMTABLE_Ce_NAME	"Cerium"
    #define CHEMTABLE_Ce_AMU	140.116
    #define CHEMTABLE_Ce_Z	58
    #define CHEMTABLE_Ce_N	82
    #define CHEMTABLE_Ce_ION	5.54
    #define CHEMTABLE_Ce_DENS	6.77
    #define CHEMTABLE_Pr_NAME	"Praseodymium"
    #define CHEMTABLE_Pr_AMU	140.908
    #define CHEMTABLE_Pr_Z	59
    #define CHEMTABLE_Pr_N	82
    #define CHEMTABLE_Pr_ION	5.47
    #define CHEMTABLE_Pr_DENS	6.77
    #define CHEMTABLE_Nd_NAME	"Neodymium"
    #define CHEMTABLE_Nd_AMU	144.24
    #define CHEMTABLE_Nd_Z	60
    #define CHEMTABLE_Nd_N	84
    #define CHEMTABLE_Nd_ION	5.53
    #define CHEMTABLE_Nd_DENS	7.01
    #define CHEMTABLE_Pm_NAME	"Promethium"
    #define CHEMTABLE_Pm_AMU	145
    #define CHEMTABLE_Pm_Z	61
    #define CHEMTABLE_Pm_N	84
    #define CHEMTABLE_Pm_ION	5.58
    #define CHEMTABLE_Pm_DENS	7.3
    #define CHEMTABLE_Sm_NAME	"Samarium"
    #define CHEMTABLE_Sm_AMU	150.36
    #define CHEMTABLE_Sm_Z	62
    #define CHEMTABLE_Sm_N	88
    #define CHEMTABLE_Sm_ION	5.64
    #define CHEMTABLE_Sm_DENS	7.52
    #define CHEMTABLE_Eu_NAME	"Europium"
    #define CHEMTABLE_Eu_AMU	151.964
    #define CHEMTABLE_Eu_Z	63
    #define CHEMTABLE_Eu_N	89
    #define CHEMTABLE_Eu_ION	5.67
    #define CHEMTABLE_Eu_DENS	5.24
    #define CHEMTABLE_Gd_NAME	"Gadolinium"
    #define CHEMTABLE_Gd_AMU	157.25
    #define CHEMTABLE_Gd_Z	64
    #define CHEMTABLE_Gd_N	93
    #define CHEMTABLE_Gd_ION	6.15
    #define CHEMTABLE_Gd_DENS	7.9
    #define CHEMTABLE_Tb_NAME	"Terbium"
    #define CHEMTABLE_Tb_AMU	158.925
    #define CHEMTABLE_Tb_Z	65
    #define CHEMTABLE_Tb_N	94
    #define CHEMTABLE_Tb_ION	5.86
    #define CHEMTABLE_Tb_DENS	8.23
    #define CHEMTABLE_Dy_NAME	"Dysprosium"
    #define CHEMTABLE_Dy_AMU	162.5
    #define CHEMTABLE_Dy_Z	66
    #define CHEMTABLE_Dy_N	97
    #define CHEMTABLE_Dy_ION	5.94
    #define CHEMTABLE_Dy_DENS	8.55
    #define CHEMTABLE_Ho_NAME	"Holmium"
    #define CHEMTABLE_Ho_AMU	164.93
    #define CHEMTABLE_Ho_Z	67
    #define CHEMTABLE_Ho_N	98
    #define CHEMTABLE_Ho_ION	6.02
    #define CHEMTABLE_Ho_DENS	8.8
    #define CHEMTABLE_Er_NAME	"Erbium"
    #define CHEMTABLE_Er_AMU	167.259
    #define CHEMTABLE_Er_Z	68
    #define CHEMTABLE_Er_N	99
    #define CHEMTABLE_Er_ION	6.11
    #define CHEMTABLE_Er_DENS	9.07
    #define CHEMTABLE_Tm_NAME	"Thulium"
    #define CHEMTABLE_Tm_AMU	168.934
    #define CHEMTABLE_Tm_Z	69
    #define CHEMTABLE_Tm_N	100
    #define CHEMTABLE_Tm_ION	6.18
    #define CHEMTABLE_Tm_DENS	9.32
    #define CHEMTABLE_Yb_NAME	"Ytterbium"
    #define CHEMTABLE_Yb_AMU	173.04
    #define CHEMTABLE_Yb_Z	70
    #define CHEMTABLE_Yb_N	103
    #define CHEMTABLE_Yb_ION	6.25
    #define CHEMTABLE_Yb_DENS	6.9
    #define CHEMTABLE_Lu_NAME	"Lutetium"
    #define CHEMTABLE_Lu_AMU	174.967
    #define CHEMTABLE_Lu_Z	71
    #define CHEMTABLE_Lu_N	104
    #define CHEMTABLE_Lu_ION	5.43
    #define CHEMTABLE_Lu_DENS	9.84
    #define CHEMTABLE_Hf_NAME	"Hafnium"
    #define CHEMTABLE_Hf_AMU	178.49
    #define CHEMTABLE_Hf_Z	72
    #define CHEMTABLE_Hf_N	106
    #define CHEMTABLE_Hf_ION	6.83
    #define CHEMTABLE_Hf_DENS	13.31
    #define CHEMTABLE_Ta_NAME	"Tantalum"
    #define CHEMTABLE_Ta_AMU	180.948
    #define CHEMTABLE_Ta_Z	73
    #define CHEMTABLE_Ta_N	108
    #define CHEMTABLE_Ta_ION	7.55
    #define CHEMTABLE_Ta_DENS	16.65
    #define CHEMTABLE_W_NAME	"Tungsten"
    #define CHEMTABLE_W_AMU	183.84
    #define CHEMTABLE_W_Z	74
    #define CHEMTABLE_W_N	110
    #define CHEMTABLE_W_ION	7.86
    #define CHEMTABLE_W_DENS	19.35
    #define CHEMTABLE_Re_NAME	"Rhenium"
    #define CHEMTABLE_Re_AMU	186.207
    #define CHEMTABLE_Re_Z	75
    #define CHEMTABLE_Re_N	111
    #define CHEMTABLE_Re_ION	7.83
    #define CHEMTABLE_Re_DENS	21.04
    #define CHEMTABLE_Os_NAME	"Osmium"
    #define CHEMTABLE_Os_AMU	190.23
    #define CHEMTABLE_Os_Z	76
    #define CHEMTABLE_Os_N	114
    #define CHEMTABLE_Os_ION	8.44
    #define CHEMTABLE_Os_DENS	22.6
    #define CHEMTABLE_Ir_NAME	"Iridium"
    #define CHEMTABLE_Ir_AMU	192.217
    #define CHEMTABLE_Ir_Z	77
    #define CHEMTABLE_Ir_N	115
    #define CHEMTABLE_Ir_ION	8.97
    #define CHEMTABLE_Ir_DENS	22.4
    #define CHEMTABLE_Pt_NAME	"Platinum"
    #define CHEMTABLE_Pt_AMU	195.078
    #define CHEMTABLE_Pt_Z	78
    #define CHEMTABLE_Pt_N	117
    #define CHEMTABLE_Pt_ION	8.96
    #define CHEMTABLE_Pt_DENS	21.45
    #define CHEMTABLE_Au_NAME	"Gold"
    #define CHEMTABLE_Au_AMU	196.967
    #define CHEMTABLE_Au_Z	79
    #define CHEMTABLE_Au_N	118
    #define CHEMTABLE_Au_ION	9.23
    #define CHEMTABLE_Au_DENS	19.32
    #define CHEMTABLE_Hg_NAME	"Mercury"
    #define CHEMTABLE_Hg_AMU	200.59
    #define CHEMTABLE_Hg_Z	80
    #define CHEMTABLE_Hg_N	121
    #define CHEMTABLE_Hg_ION	10.44
    #define CHEMTABLE_Hg_DENS	13.55
    #define CHEMTABLE_Tl_NAME	"Thallium"
    #define CHEMTABLE_Tl_AMU	204.383
    #define CHEMTABLE_Tl_Z	81
    #define CHEMTABLE_Tl_N	123
    #define CHEMTABLE_Tl_ION	6.11
    #define CHEMTABLE_Tl_DENS	11.85
    #define CHEMTABLE_Pb_NAME	"Lead"
    #define CHEMTABLE_Pb_AMU	207.2
    #define CHEMTABLE_Pb_Z	82
    #define CHEMTABLE_Pb_N	125
    #define CHEMTABLE_Pb_ION	7.42
    #define CHEMTABLE_Pb_DENS	11.35
    #define CHEMTABLE_Bi_NAME	"Bismuth"
    #define CHEMTABLE_Bi_AMU	208.98
    #define CHEMTABLE_Bi_Z	83
    #define CHEMTABLE_Bi_N	126
    #define CHEMTABLE_Bi_ION	7.29
    #define CHEMTABLE_Bi_DENS	9.75
    #define CHEMTABLE_Po_NAME	"Polonium"
    #define CHEMTABLE_Po_AMU	209
    #define CHEMTABLE_Po_Z	84
    #define CHEMTABLE_Po_N	125
    #define CHEMTABLE_Po_ION	8.42
    #define CHEMTABLE_Po_DENS	9.3
    #define CHEMTABLE_At_NAME	"Astatine"
    #define CHEMTABLE_At_AMU	210
    #define CHEMTABLE_At_Z	85
    #define CHEMTABLE_At_N	125
    #define CHEMTABLE_At_ION	9.3
    #define CHEMTABLE_At_DENS	0
    #define CHEMTABLE_Rn_NAME	"Radon"
    #define CHEMTABLE_Rn_AMU	222
    #define CHEMTABLE_Rn_Z	86
    #define CHEMTABLE_Rn_N	136
    #define CHEMTABLE_Rn_ION	10.75
    #define CHEMTABLE_Rn_DENS	9.73
    #define CHEMTABLE_Fr_NAME	"Francium"
    #define CHEMTABLE_Fr_AMU	223
    #define CHEMTABLE_Fr_Z	87
    #define CHEMTABLE_Fr_N	136
    #define CHEMTABLE_Fr_ION	4.07
    #define CHEMTABLE_Fr_DENS	0
    #define CHEMTABLE_Ra_NAME	"Radium"
    #define CHEMTABLE_Ra_AMU	226
    #define CHEMTABLE_Ra_Z	88
    #define CHEMTABLE_Ra_N	138
    #define CHEMTABLE_Ra_ION	5.28
    #define CHEMTABLE_Ra_DENS	5.5
    #define CHEMTABLE_Ac_NAME	"Actinium"
    #define CHEMTABLE_Ac_AMU	227
    #define CHEMTABLE_Ac_Z	89
    #define CHEMTABLE_Ac_N	138
    #define CHEMTABLE_Ac_ION	5.17
    #define CHEMTABLE_Ac_DENS	10.07
    #define CHEMTABLE_Th_NAME	"Thorium"
    #define CHEMTABLE_Th_AMU	232.038
    #define CHEMTABLE_Th_Z	90
    #define CHEMTABLE_Th_N	142
    #define CHEMTABLE_Th_ION	6.31
    #define CHEMTABLE_Th_DENS	11.72
    #define CHEMTABLE_Pa_NAME	"Protactinium"
    #define CHEMTABLE_Pa_AMU	231.036
    #define CHEMTABLE_Pa_Z	91
    #define CHEMTABLE_Pa_N	140
    #define CHEMTABLE_Pa_ION	5.89
    #define CHEMTABLE_Pa_DENS	15.4
    #define CHEMTABLE_U_NAME	"Uranium"
    #define CHEMTABLE_U_AMU	238.029
    #define CHEMTABLE_U_Z	92
    #define CHEMTABLE_U_N	146
    #define CHEMTABLE_U_ION	6.19
    #define CHEMTABLE_U_DENS	18.95
    #define CHEMTABLE_Np_NAME	"Neptunium"
    #define CHEMTABLE_Np_AMU	237
    #define CHEMTABLE_Np_Z	93
    #define CHEMTABLE_Np_N	144
    #define CHEMTABLE_Np_ION	6.27
    #define CHEMTABLE_Np_DENS	20.2
    #define CHEMTABLE_Pu_NAME	"Plutonium"
    #define CHEMTABLE_Pu_AMU	244
    #define CHEMTABLE_Pu_Z	94
    #define CHEMTABLE_Pu_N	150
    #define CHEMTABLE_Pu_ION	6.03
    #define CHEMTABLE_Pu_DENS	19.84
    #define CHEMTABLE_Am_NAME	"Americium"
    #define CHEMTABLE_Am_AMU	243
    #define CHEMTABLE_Am_Z	95
    #define CHEMTABLE_Am_N	148
    #define CHEMTABLE_Am_ION	5.97
    #define CHEMTABLE_Am_DENS	13.67
    #define CHEMTABLE_Cm_NAME	"Curium"
    #define CHEMTABLE_Cm_AMU	247
    #define CHEMTABLE_Cm_Z	96
    #define CHEMTABLE_Cm_N	151
    #define CHEMTABLE_Cm_ION	5.99
    #define CHEMTABLE_Cm_DENS	13.5
    #define CHEMTABLE_Bk_NAME	"Berkelium"
    #define CHEMTABLE_Bk_AMU	247
    #define CHEMTABLE_Bk_Z	97
    #define CHEMTABLE_Bk_N	150
    #define CHEMTABLE_Bk_ION	6.2
    #define CHEMTABLE_Bk_DENS	14.78
    #define CHEMTABLE_Cf_NAME	"Californium"
    #define CHEMTABLE_Cf_AMU	251
    #define CHEMTABLE_Cf_Z	98
    #define CHEMTABLE_Cf_N	153
    #define CHEMTABLE_Cf_ION	6.28
    #define CHEMTABLE_Cf_DENS	15.1
    #define CHEMTABLE_Es_NAME	"Einsteinium"
    #define CHEMTABLE_Es_AMU	252
    #define CHEMTABLE_Es_Z	99
    #define CHEMTABLE_Es_N	153
    #define CHEMTABLE_Es_ION	6.42
    #define CHEMTABLE_Es_DENS	0
    #define CHEMTABLE_Fm_NAME	"Fermium"
    #define CHEMTABLE_Fm_AMU	257
    #define CHEMTABLE_Fm_Z	100
    #define CHEMTABLE_Fm_N	157
    #define CHEMTABLE_Fm_ION	6.5
    #define CHEMTABLE_Fm_DENS	0
    #define CHEMTABLE_Md_NAME	"Mendelevium"
    #define CHEMTABLE_Md_AMU	258
    #define CHEMTABLE_Md_Z	101
    #define CHEMTABLE_Md_N	157
    #define CHEMTABLE_Md_ION	6.58
    #define CHEMTABLE_Md_DENS	0
    #define CHEMTABLE_No_NAME	"Nobelium"
    #define CHEMTABLE_No_AMU	259
    #define CHEMTABLE_No_Z	102
    #define CHEMTABLE_No_N	157
    #define CHEMTABLE_No_ION	6.65
    #define CHEMTABLE_No_DENS	0
    #define CHEMTABLE_Lr_NAME	"Lawrencium"
    #define CHEMTABLE_Lr_AMU	262
    #define CHEMTABLE_Lr_Z	103
    #define CHEMTABLE_Lr_N	159
    #define CHEMTABLE_Lr_ION	4.9
    #define CHEMTABLE_Lr_DENS	0
    #define CHEMTABLE_Rf_NAME	"Rutherfordium"
    #define CHEMTABLE_Rf_AMU	261
    #define CHEMTABLE_Rf_Z	104
    #define CHEMTABLE_Rf_N	157
    #define CHEMTABLE_Rf_ION	0
    #define CHEMTABLE_Rf_DENS	0
    #define CHEMTABLE_Db_NAME	"Dubnium"
    #define CHEMTABLE_Db_AMU	262
    #define CHEMTABLE_Db_Z	105
    #define CHEMTABLE_Db_N	157
    #define CHEMTABLE_Db_ION	0
    #define CHEMTABLE_Db_DENS	0
    #define CHEMTABLE_Sg_NAME	"Seaborgium"
    #define CHEMTABLE_Sg_AMU	266
    #define CHEMTABLE_Sg_Z	106
    #define CHEMTABLE_Sg_N	160
    #define CHEMTABLE_Sg_ION	0
    #define CHEMTABLE_Sg_DENS	0
    #define CHEMTABLE_Bh_NAME	"Bohrium"
    #define CHEMTABLE_Bh_AMU	264
    #define CHEMTABLE_Bh_Z	107
    #define CHEMTABLE_Bh_N	157
    #define CHEMTABLE_Bh_ION	0
    #define CHEMTABLE_Bh_DENS	0
    #define CHEMTABLE_Hs_NAME	"Hassium"
    #define CHEMTABLE_Hs_AMU	277
    #define CHEMTABLE_Hs_Z	108
    #define CHEMTABLE_Hs_N	169
    #define CHEMTABLE_Hs_ION	0
    #define CHEMTABLE_Hs_DENS	0
    #define CHEMTABLE_Mt_NAME	"Meitnerium"
    #define CHEMTABLE_Mt_AMU	268
    #define CHEMTABLE_Mt_Z	109
    #define CHEMTABLE_Mt_N	159
    #define CHEMTABLE_Mt_ION	0
    #define CHEMTABLE_Mt_DENS	0
    #define CHEMTABLE_Ds_NAME	"Darmstadtium"
    #define CHEMTABLE_Ds_AMU	281
    #define CHEMTABLE_Ds_Z	110
    #define CHEMTABLE_Ds_N	171
    #define CHEMTABLE_Ds_ION	0
    #define CHEMTABLE_Ds_DENS	0
    #define CHEMTABLE_Rg_NAME	"Roentgenium"
    #define CHEMTABLE_Rg_AMU	282
    #define CHEMTABLE_Rg_Z	111
    #define CHEMTABLE_Rg_N	171
    #define CHEMTABLE_Rg_ION	0
    #define CHEMTABLE_Rg_DENS	0
    #define CHEMTABLE_Cn_NAME	"Copernicium"
    #define CHEMTABLE_Cn_AMU	285
    #define CHEMTABLE_Cn_Z	112
    #define CHEMTABLE_Cn_N	173
    #define CHEMTABLE_Cn_ION	0
    #define CHEMTABLE_Cn_DENS	0
    #define CHEMTABLE_Nh_NAME	"Nihonium"
    #define CHEMTABLE_Nh_AMU	286
    #define CHEMTABLE_Nh_Z	113
    #define CHEMTABLE_Nh_N	173
    #define CHEMTABLE_Nh_ION	0
    #define CHEMTABLE_Nh_DENS	0
    #define CHEMTABLE_Fl_NAME	"Flerovium"
    #define CHEMTABLE_Fl_AMU	289
    #define CHEMTABLE_Fl_Z	114
    #define CHEMTABLE_Fl_N	175
    #define CHEMTABLE_Fl_ION	0
    #define CHEMTABLE_Fl_DENS	0
    #define CHEMTABLE_Mc_NAME	"Moscovium"
    #define CHEMTABLE_Mc_AMU	290
    #define CHEMTABLE_Mc_Z	115
    #define CHEMTABLE_Mc_N	175
    #define CHEMTABLE_Mc_ION	0
    #define CHEMTABLE_Mc_DENS	0
    #define CHEMTABLE_Lv_NAME	"Livermorium"
    #define CHEMTABLE_Lv_AMU	293
    #define CHEMTABLE_Lv_Z	116
    #define CHEMTABLE_Lv_N	177
    #define CHEMTABLE_Lv_ION	0
    #define CHEMTABLE_Lv_DENS	0
    #define CHEMTABLE_Ts_NAME	"Tennessine"
    #define CHEMTABLE_Ts_AMU	294
    #define CHEMTABLE_Ts_Z	117
    #define CHEMTABLE_Ts_N	177
    #define CHEMTABLE_Ts_ION	0
    #define CHEMTABLE_Ts_DENS	0
    #define CHEMTABLE_Og_NAME	"Oganesson"
    #define CHEMTABLE_Og_AMU	294
    #define CHEMTABLE_Og_Z	118
    #define CHEMTABLE_Og_N	176
    #define CHEMTABLE_Og_ION	0
    #define CHEMTABLE_Og_DENS	0

#endif  //level 3




#define UNICONVERT(from, to)	( (to) / (from) )

#endif		//Science constant
































//=======================/ Bit utils /============================
#if USEFULHEADER_BITOPS_LEVEL >= 1

//! Создаёт выражение из по номеру бита.
#define BIT(bit)				(1U<<(bit))
//! Устанавливает бит в выражении.
#define BIT_SET(expr, bit)		( (expr) | (1UL<<(bit)) )
//! Очищает бит в выражении.
#define BIT_CLR(expr, bit)    	( (expr) & ~(1UL<<(bit)) )
//! Инвертирует бит в выражении.
#define BIT_FLIP(expr, bit)   	( (expr) ^ (1UL<<(bit)) )
//! Проверяет на установку бита в выражении.
#define BIT_IS_SET(expr, bit)  	( ((expr) & (1UL<<(bit))) != 0 )
//! Проверяет на снятие бита в выражении.
#define BIT_IS_CLR(expr, bit)	( ((expr) & (1UL<<(bit))) == 0 )
//! Проверяет бит на падение
#define BIT_IS_FALL(t1, t2) 	( ((t1) & !(t2)) & 0x1 )
//! Проверяет бит на рост
#define BIT_IS_RISE(t1, t2) 	( (!(t1) & (t2)) & 0x1 )
//! Проверяет бит на переключение
#define BIT_IS_FLIP(t1, t2) 	( ((t1) ^ (t2)) & 0x1 )

//! Устанавливает биты в выражении.
#define BITS_SET(expr, bits)		( (expr) | (bits) )
//! Устанавливает биты в выражении через маску.
#define BITS_SET_MASKED(expr, bits, mask)		( (expr) | ((mask) & (bits)) )

//! Очищает биты в выражении.
#define BITS_CLR(expr, bits)    	( (expr) & ~(bits) )
//! Очищает биты в выражении через маску.
#define BITS_CLR_MASKED(expr, bits, mask)    	( (expr) & ~((mask) & (bits)) )

//! Инвертирует биты в выражении.
#define BITS_FLIP(expr, bits)   	( (expr) ^ (bits) )
//! Инвертирует биты в выражении через маску.
#define BITS_FLIP_MASKED(expr, bits, mask)   	( (expr) ^ ((mask) & (bits)) )

//! Проверяет на установку битов в выражении.
#define BITS_IS_SET(expr, bits)  	( ((expr) & (bits)) == (bits) )
//! Проверяет на снятие битов в выражении.
#define BITS_IS_CLR(expr, bits)		( ((expr) & (bits)) == 0 )
//! Проверяет биты на падение
#define BITS_IS_FALL(t1, t2, mask) 	( (((t1) ^ ~(t2)) & (mask)) == 0 )
//! Проверяет биты на рост
#define BITS_IS_RISE(t1, t2, mask) 	( ((~(t1) ^ (t2)) & (mask)) == 0 )
//! Проверяет биты на переключение
#define BITS_IS_FLIP(t1, t2, mask) 	( (((t1) ^ (t2)) & (mask)) == (mask) )

//! Заливает единицами биты от F до L
#define BITS_FILL(first, size)		( (~(0xffffffffffffffff<<(size))) << (first) )


//======================/ Byte utils /=====================================
#define MAKE8_BITS(	bit7, \
                    bit6, \
                    bit5, \
                    bit4, \
                    bit3, \
                    bit2, \
                    bit1, \
                    bit0 )			(	(((bit0)&1)<<0) | (((bit1)&1)<<1) | \
                                        (((bit2)&1)<<2) | (((bit3)&1)<<3) | \
                                        (((bit4)&1)<<4) | (((bit5)&1)<<5) | \
                                        (((bit6)&1)<<6) | (((bit7)&1)<<7)	)

//! Собирает 16-битную труктуру из 2 8-битных.
#define MAKE16_8(	part2, \
                    part1) 		   	( 	(((uint16_t)(part2) & 0xff)<<8) | 		\
                                        (((uint16_t)(part1) & 0xff)<<0) )

//! Собирает 32-битную структуру из 4 8-битных.
#define MAKE32_8(	part4, \
                    part3, \
                    part2, \
                    part1)			(	(((uint32_t)(part4) & 0xff)<<24) | 		\
                                        (((uint32_t)(part3) & 0xff)<<16) | 		\
                                        (((uint32_t)(part2) & 0xff)<<8) | 		\
                                        (((uint32_t)(part1) & 0xff)<<0) )

//! Собирает 32-битную структуру из 2 16-битных.
#define MAKE32_16(	part2, \
                    part1)			( 	(((uint32_t)(part2) & 0xffff)<<16) | 		\
                                        (((uint32_t)(part1) & 0xffff)<<0) )

//! Собирает 64-битную структуру из 8 8-битных.
#define MAKE64_8(	part8, \
                    part7, \
                    part6, \
                    part5, \
                    part4, \
                    part3, \
                    part2, \
                    part1 )		  	(  	(((uint64_t)(part8) & 0xff)<<56) | 		\
                                        (((uint64_t)(part7) & 0xff)<<48) | 		\
                                        (((uint64_t)(part6) & 0xff)<<40) | 		\
                                        (((uint64_t)(part5) & 0xff)<<32) | 		\
                                        (((uint64_t)(part4) & 0xff)<<24) | 		\
                                        (((uint64_t)(part3) & 0xff)<<16) | 		\
                                        (((uint64_t)(part2) & 0xff)<<8) | 		\
                                        (((uint64_t)(part1) & 0xff)<<0) )

//! Собирает 64-битную структуру из 4 16-битных.
#define MAKE64_16(	part4, \
                    part3, \
                    part2, \
                    part1)			  	(   (((uint64_t)(part4) & 0xffff)<<48) | 		\
                                            (((uint64_t)(part3) & 0xffff)<<32) | 		\
                                            (((uint64_t)(part2) & 0xffff)<<16) | 		\
                                            (((uint64_t)(part1) & 0xffff)<<0) )

//! Собирает 64-битную структуру из 2 32-битных.
#define MAKE64_32(part2, part1)		  	( 	(((uint64_t)(part2) & 0xffffffff)<<32) | 	\
                                            (((uint64_t)(part1) & 0xffffffff)<<0) )


//! Выбирает 8-битную часть из выражения.
#define TAKE8(expr, num)				   	( ((expr)>>((num)<<3)) & 0xff )
//! Выбирает 16-битную часть из выражения.
#define TAKE16(expr, num)				( ((expr)>>((num)<<4)) & 0xffff )
//! Выбирает 32-битную часть из выражения.
#define TAKE32(expr, num)				( ((expr)>>((num)<<5)) & 0xffffffff )


#define GET_FIELD(expr, offset, width)			( ((expr) >> (offset)) & BITS_FILL(offset, width) )
#define SET_FIELD(expr, offset, width, val)		( ((expr) & ~BITS_FILL(offset, width) | (((val) & BITS_FILL(0, width)) << (offset) )

#endif




//===================/ Constraining /=====================
//! Constraining value in range from min to max
#define CONSTRAIN(expr, min, max)  			( ((expr) > (max)) ? (max) : ((expr) < (min)) ? (min) :	(expr) )
//! Modular constraining value in range from min to max
#define CONSTRAIN_CIRC(expr, min, max)		( (min) + (expr) % ((max) - (min)) )




//===================/ Getter macros /=========================
#define METHOD_GETTER_CREATE(propname, proptype)					proptype propname() const
#define METHOD_GETTER_IMPL(classname, propname, proptype)			proptype classname::get##propname() const

#define METHOD_SETTER_CREATE(propname, proptype)						void set##propname(const proptype& value)
#define METHOD_SETTER_IMPL(classname, propname, proptype)				void classname::set##propname(const proptype& value)

#define METHOD_SETTER2_CREATE(propname, proptype1, proptype2)			void set##propname(const proptype1& value1, const proptype2 &value2)
#define METHOD_SETTER2_IMPL(classname, propname, proptype1, proptype2)	void classname::set##propname(const proptype1& value1, const proptype2 &value2)





//==================/ Typing /===================================
//! Forced cast type. Like as reinterpret_cast, but more brutal
#define FORCE_CAST(type, var) 		( *((type*)((void*)&(var))) )

//! Autocreate static array
#define CREATE_ARRAY(name, size, type)		type name[size]


//==================/ Operations /===============================
//! Use N-times member of class or struct, Maybe template as array[indexer].method1(), or array[indexer].member = variable
#define USE_MULTIPLE(array, count, member_exp)		{for(int indexer=0; indexer<count; indexer++)	array[indexer].member_exp;}

//! Eternal loop. You may leave loop using 'break'
#define FOREVER()		while(1)

//! For each element throught iterator
#define FOREACH(iter, container)	for(iter = container.begin(); iter != container.end(); iter++)










//======================/ USEFUL TYPES AND FUNCTIONS /====================================
//! Float 32-bit alias
typedef float float32_t;
//! Float 64-bit alias
#if DBL_MANT_DIG == 53
    typedef double float64_t;
#elif LDBL_MANT_DIG == 53
    typedef long double float64_t;
#endif
//! Float 80-bit alias
#if LDBL_MANT_DIG == 64
    typedef long double float80_t;
#endif



//! Expanded bit structure of float 32-bit
typedef union {
    //! Bits
    struct {
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign :     1;
    }bit;

    float32_t Vf32;
    uint32_t Vui32;
    int32_t Vi32;
} TFloatBit32;






//! Expanded bit structure of float 64-bit
typedef union {
    struct {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign :     1;
    } bit;

    float64_t Vf64;
    uint64_t Vui64;
    int64_t Vi64;
} TFloatBit64;


//! Expanded bit structure of float 80-bit
typedef union {
    struct {
        uint64_t mantissa : 63;
        uint64_t intpart :  1;
        uint16_t exponent : 15;
        uint16_t sign :     1;
    } bit;
#if LDBL_MANT_DIG == 64
    float80_t Vf80;
#endif
} TFloatBit80;


//! Expanded bit structure of float 128-bit
typedef union {
    struct {
        uint64_t mantissa_low : 64;
        uint64_t mantissa_hi :  48;
        uint64_t exponent :     15;
        uint64_t sign :         1;
    } bit;
} TFloatBit128;






//! Union data struct 16-bit
typedef union {

#if CHAR_BIT == 8
    int8_t	Vi8[2];
    uint8_t Vui8[2];
    int8_t	Vi8_;
    uint8_t	Vui8_;
#elif CHAR_BIT == 16
    int_least8_t    Vi8_ : 8;
    uint_least8_t	Vui8_ : 8;
#endif

    uint16_t Vui16;
    int16_t Vi16;

    struct {
        uint_least8_t b0 :1; uint_least8_t b1 :1; uint_least8_t b2 :1; uint_least8_t b3 :1;
        uint_least8_t b4 :1; uint_least8_t b5 :1; uint_least8_t b6 :1; uint_least8_t b7 :1;
        uint_least8_t b8 :1; uint_least8_t b9 :1; uint_least8_t b10 :1; uint_least8_t b11 :1;
        uint_least8_t b12 :1; uint_least8_t b13 :1; uint_least8_t b14 :1; uint_least8_t b15 :1;
    } bit;

    struct {
        uint_least8_t byte0 : 8;
        uint_least8_t byte1 : 8;
    } byte;

} TData16;



//! Union data struct 32-bit
typedef union {

#if CHAR_BIT == 8
    int8_t 		Vi8[4];
    uint8_t 	Vui8[4];
    int8_t		Vi8_;
    uint8_t		Vui8_;
#elif CHAR_BIT == 16
    int_least8_t    Vi8_ : 8;
    uint_least8_t	Vui8_ : 8;
#endif

    int16_t 	Vi16[2];
    uint16_t 	Vui16[2];
    int16_t		Vi16_;
    uint16_t	Vui16_;

    int32_t 	Vi32;
    uint32_t 	Vui32;

    float32_t 		Vf32;
    TFloatBit32 Vfbit32;

    struct {
        uint_least8_t b0 :1; uint_least8_t b1 :1; uint_least8_t b2 :1; uint_least8_t b3 :1;
        uint_least8_t b4 :1; uint_least8_t b5 :1; uint_least8_t b6 :1; uint_least8_t b7 :1;
        uint_least8_t b8 :1; uint_least8_t b9 :1; uint_least8_t b10 :1; uint_least8_t b11 :1;
        uint_least8_t b12 :1; uint_least8_t b13 :1; uint_least8_t b14 :1; uint_least8_t b15 :1;
        uint_least8_t b16 :1; uint_least8_t b17 :1; uint_least8_t b18 :1; uint_least8_t b19 :1;
        uint_least8_t b20 :1; uint_least8_t b21 :1;	uint_least8_t b22 :1; uint_least8_t b23 :1;
        uint_least8_t b24 :1; uint_least8_t b25 :1;	uint_least8_t b26 :1; uint_least8_t b27 :1;
        uint_least8_t b28 :1; uint_least8_t b29 :1;	uint_least8_t b30 :1; uint_least8_t b31 :1;
    } bit;

    struct {
        uint_least8_t byte0 : 8;
        uint_least8_t byte1 : 8;
        uint_least8_t byte2 : 8;
        uint_least8_t byte3 : 8;
    } byte;

} TData32;






//! Union data struct 64-bit
typedef union {

#if CHAR_BIT == 8
    int8_t 		Vi8[8];
    uint8_t 	Vui8[8];
    int8_t		Vi8_;
    uint8_t		Vui8_;
#elif CHAR_BIT == 16
    int_least8_t    Vi8_ : 8;
    uint_least8_t	Vui8_ : 8;
#endif

    int16_t 	Vi16[4];
    uint16_t 	Vui16[4];
    int16_t		Vi16_;
    uint16_t	Vui16_;

    int32_t 	Vi32[2];
    uint32_t 	Vui32[2];
    int32_t		Vi32_;
    uint32_t	Vui32_;

    int64_t 	Vi64;
    uint64_t 	Vui64;

    float32_t 		Vf32[2];
    float32_t 		Vf32_;
    TFloatBit32 Vfbit32[2];
    TFloatBit32 Vfbit32_;

    float64_t Vf64;
    TFloatBit64 Vfbit64;

    struct {
        uint_least8_t b0 :1; uint_least8_t b1 :1; uint_least8_t b2 :1; uint_least8_t b3 :1;
        uint_least8_t b4 :1; uint_least8_t b5 :1; uint_least8_t b6 :1; uint_least8_t b7 :1;
        uint_least8_t b8 :1; uint_least8_t b9 :1; uint_least8_t b10 :1; uint_least8_t b11 :1;
        uint_least8_t b12 :1; uint_least8_t b13 :1; uint_least8_t b14 :1; uint_least8_t b15 :1;
        uint_least8_t b16 :1; uint_least8_t b17 :1; uint_least8_t b18 :1; uint_least8_t b19 :1;
        uint_least8_t b20 :1; uint_least8_t b21 :1;	uint_least8_t b22 :1; uint_least8_t b23 :1;
        uint_least8_t b24 :1; uint_least8_t b25 :1;	uint_least8_t b26 :1; uint_least8_t b27 :1;
        uint_least8_t b28 :1; uint_least8_t b29 :1;	uint_least8_t b30 :1; uint_least8_t b31 :1;
        uint_least8_t b32 :1; uint_least8_t b33 :1; uint_least8_t b34 :1; uint_least8_t b35 :1;
        uint_least8_t b36 :1; uint_least8_t b37 :1; uint_least8_t b38 :1; uint_least8_t b39 :1;
        uint_least8_t b40 :1; uint_least8_t b41 :1; uint_least8_t b42 :1; uint_least8_t b43 :1;
        uint_least8_t b44 :1; uint_least8_t b45 :1; uint_least8_t b46 :1; uint_least8_t b47 :1;
        uint_least8_t b48 :1; uint_least8_t b49 :1; uint_least8_t b50 :1; uint_least8_t b51 :1;
        uint_least8_t b52 :1; uint_least8_t b53 :1; uint_least8_t b54 :1; uint_least8_t b55 :1;
        uint_least8_t b56 :1; uint_least8_t b57 :1; uint_least8_t b58 :1; uint_least8_t b59 :1;
        uint_least8_t b60 :1; uint_least8_t b61 :1; uint_least8_t b62 :1; uint_least8_t b63 :1;
    } bit;

    struct {
        uint_least8_t byte0 : 8;
        uint_least8_t byte1 : 8;
        uint_least8_t byte2 : 8;
        uint_least8_t byte3 : 8;
        uint_least8_t byte4 : 8;
        uint_least8_t byte5 : 8;
        uint_least8_t byte6 : 8;
        uint_least8_t byte7 : 8;
    } byte;

} TData64;








































#ifdef __cplusplus





template<class T>
inline T constrain(T value, T min, T max)  {
    return CONSTRAIN(value, min, max);
}

//! Преобразование в код Грея
template<class T>
inline T grey_code(T expr)  {
    return expr ^ (expr >> 1);
}

//! Преобразование из кода Грея
template<class T>
inline T grey_decode(T expr)  {
    T bin;
    for (bin = 0; expr; expr >>= 1) {
        bin ^= expr;
    }
    return bin;
}

//! Force cast type F to type T
template<class T, class F>
inline T &force_cast(F &f)  {
    return *(T*) (void*) &f;
}

//! Swap values
template<class T>
void swapValues(T &l, T &r)  {
    T tmp = l;
    l = r;
    r = tmp;
}

//! Assigment value to var, and if(var==value) return TRUE
template<class T>
bool assignment(T &var, T value)  {
    if (var == value)
        return false;
    else
        var = value;
    return true;
}


//! Fill data values
template<class T>
void fillValues(T *array, int size, const T& value)  {
    while(size-->0)
        *(array++) = value;
}

//! Fill data nulls
template<class T>
void fillZeros(T &object)  {
    memset(&object, 0, sizeof(T));
}
//! Fill data nulls
template<class T>
void fillZeros(T *data, int n)  {
    memset(data, 0, sizeof(T) * n);
}

//! Fill data units
template<class T>
void fillOnes(T &object)  {
    memset(&object, -1, sizeof(T));
}

//! Fill data units
template<class T>
void fillOnes(T *data, int n)  {
    memset(data, -1, sizeof(T) * n);
}







template<unsigned N>
class CBitFlags{
private:
    unsigned char bits[(N + (CHAR_BIT*sizeof(char)) - 1) / (CHAR_BIT*sizeof(char))];
public:

    CBitFlags(){fillZeros(bits);}

    void setBit(int n, bool val){
        int byte_num = n / CHAR_BIT;
        int bin_num = 1 - (n & (CHAR_BIT-1));
        if(val)		bits[(n + (CHAR_BIT*sizeof(unsigned)) - 1) / (CHAR_BIT*sizeof(unsigned))] |= 1U<<( n & ((CHAR_BIT*sizeof(unsigned))-1) );
        else		bits[(n + (CHAR_BIT*sizeof(unsigned)) - 1) / (CHAR_BIT*sizeof(unsigned))] &= ~(1U<<( n & ((CHAR_BIT*sizeof(unsigned))-1)));
    }

    bool Bit(int n){
        return bits[(n + (CHAR_BIT*sizeof(unsigned)) - 1) / (CHAR_BIT*sizeof(unsigned))] & (1U<<( n & ((CHAR_BIT*sizeof(unsigned))-1)));
    }

};





#if USEFULHEADER_FUNCTORS_LEVEL >= 3

template<class S0, class D0, class R>
R function1_adapter(R (*fptr)(D0), S0 arg0){
    return fptr(arg0);
}

template<class S0, class S1, class D0, class D1, class R>
R function2_adapter(R (*fptr)(D0, D1), S0 arg0, S1 arg1){
    return fptr(arg0, arg1);
}

template<class S0, class S1, class S2, class D0, class D1, class D2, class R>
R function3_adapter(R (*fptr)(D0, D1, D2), S0 arg0, S1 arg1, S2 arg2){
    return fptr(arg0, arg1, arg2);
}

#endif


/*!
 * Functor realization. You may using pointers to usual function and methods,
 * and this class handling call both variants correctly and universaly
 */
template<class R = void>
class CFunctor0 {
private:
    class TClass {};
    typedef R (TClass::*TMethod)();
    typedef R (*TFunc)();

    TClass *c;
    union{
        TMethod method0;
        TFunc	function;
    } f;

public:

    //! Default constructor
    CFunctor0(){
        c = NULL;
        f.method0 = NULL;
    }


    //! Function constructor
    CFunctor0(R (*pfunc)()){
        bind(pfunc);
    }

    //! Class method0 constructor
    template<class C>
    CFunctor0(C *pclass, R (C::*pmethod)()){
        bind(pclass, pmethod);
    }

    //! Assign function pointer
    TFunc operator=(R (*pfunc)()){
        bind(pfunc);
        return pfunc;
    }


    //! Compare with other functor
    inline bool operator ==(const CFunctor0 &rhs)	const {
        return c==NULL ? (f.function == rhs.f.function) : ((c == rhs.c) && (f.method0 == rhs.f.method0));
    }

    //! Compare with function
    inline bool operator ==(R (*pfunc)())	const {
        return (c==NULL) && (f.function == pfunc);
    }

    //! Functor realization
    inline R operator()(){
        if(c != NULL)
            return ((c)->*(f.method0))();
        else if(f.function != NULL)
            return f.function();
        return R();
    }


    //! Set pointer to function
    inline void bind(R (*pfunc)()){
        c = NULL;
        f.function = pfunc;
    }

    //! Set pointer to method0
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)()){
        c = (typeof(c))pclass;
        f.method0 = (typeof(f.method0))pmethod;
    }



    bool isBinded(){
        return f.method0 == NULL;
    }

    void reset(){
        c = NULL;
        f.method0 = NULL;
    }

};







/*!
 * Functor with one argument. @see CFunctor
 */
template<class T0, class R = void>
class CFunctor1 {
private:
    class TClass {};
    typedef R (TClass::*TMethod0)();
    typedef R (TClass::*TMethod1)(T0);
    typedef R (*TFunc0)();
    typedef R (*TFunc1)(T0);


    TClass *c;
    union{
        TFunc0	function0;
        TMethod0 method0;
        TFunc1	function1;
        TMethod1 method1;
    } f;


#	if USEFULHEADER_FUNCTORS_LEVEL >= 3
    typedef R (*TAdapterF1)(TFunc1*, T0);
    typedef R (*TAdapterM1)(TClass*, TClass::*TMethod1, T0);
    void *adapter;
#	endif

    #if USEFULHEADER_FUNCTORS_LEVEL >= 2
    char num_args;
    #endif

public:

    struct Arguments{
        T0 arg0;
    };


    //! Default constructor
    CFunctor1(){
        c = NULL;
        f.method1 = NULL;
        #if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = -1;
        #endif
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class function 0 args constructor
    CFunctor1(R (*pfunc)()){
        bind(pfunc);
    }
#	endif

    //! Class function 1 args constructor
    CFunctor1(R (*pfunc)(T0)){
        bind(pfunc);
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class method 0 args constructor
    template<class C>
    CFunctor1(C *pclass, R (C::*pmethod)()){
        bind(pclass, pmethod);
    }
#	endif
    //! Class function 1 args constructor
    template<class C>
    CFunctor1(C *pclass, R (C::*pmethod)(T0)){
        bind(pclass, pmethod);
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Assign function pointer 0 args
    TFunc0 operator=(R (*pfunc)()){
        bind(pfunc);
        return pfunc;
    }
#	endif

    //! Assign function pointer 1 args
    TFunc1 operator=(R (*pfunc)(T0)){
        bind(pfunc);
        return pfunc;
    }


    //! Compare with other functor
    inline bool operator==(const CFunctor1 &rhs)	const {
        return c==NULL ? (f.function1 == rhs.f.function1) : ((c == rhs.c) && (f.method1 == rhs.f.method1));
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Compare with function 0 args
    inline bool operator==(R (*pfunc)())	const {
        return c==NULL ? (f.function0 == pfunc) : false;
    }
#	endif

    //! Compare with function 1 args
    inline bool operator==(R (*pfunc)(T0))	const {
        return c==NULL ? (f.function1 == pfunc) : false;
    }

    inline R operator()(const Arguments &args){
        return operator()(args.arg0);
    }

    //! Functor realization
    inline R operator()(T0 arg0){
        if(c != NULL){
#			if USEFULHEADER_FUNCTORS_LEVEL == 1
                return ((c)->*(f.method1))(arg0);
#			elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return ((c)->*(f.method0))();
                    case 1: return ((c)->*(f.method1))(arg0);
                };
#			endif
        }else if(f.function1 != NULL){
            #if USEFULHEADER_FUNCTORS_LEVEL == 1
                return f.function1(arg0);
            #elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return f.function0();
                    case 1: return f.function1(arg0);
                };
            #endif
        }
        return R();
    }



#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to function of 0 arguments
    inline void bind(R (*pfunc)()){
        c = NULL;
        f.function0 = pfunc;
        num_args = 0;
    }
#	endif

    //! Set pointer to function of 1 arguments
    inline void bind(R (*pfunc)(T0)){
        c = NULL;
        f.function1 = pfunc;
        #if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 1;
        #endif
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to method of 0 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)()){
        c = (TClass*)pclass;
        f.method0 = (TMethod0)pmethod;
        num_args = 0;
    }
#	endif

    //! Set pointer to method of 1 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0)){
        c = (TClass*)pclass;
        f.method1 = (TMethod1)pmethod;
#		if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 1;
#		endif
    }


    bool isBinded(){
        return f.method0 == NULL;
    }

    void reset(){
        c = NULL;
        f.method0 = NULL;
    }

};






/*!
 * Functor with two arguments. @see CFunctor
 */
template<class T0, class T1, class R = void>
class CFunctor2 {
private:
    class TClass {};
    typedef R (TClass::*TMethod0)();
    typedef R (TClass::*TMethod1)(T0);
    typedef R (TClass::*TMethod2)(T0, T1);
    typedef R (*TFunc0)();
    typedef R (*TFunc1)(T0);
    typedef R (*TFunc2)(T0, T1);

    TClass *c;
    union{
        TFunc0	function0;
        TMethod0 method0;
        TFunc1	function1;
        TMethod1 method1;
        TFunc2	function2;
        TMethod2 method2;
    } f;
#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    char num_args;
#	endif
public:

    struct Arguments{
        T0 arg0;
        T1 arg1;
    };


    //! Default constructor
    CFunctor2(){
        c = NULL;
        f.method2 = NULL;
#		if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = -1;
#		endif
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class function 0 args constructor
    CFunctor2(R (*pfunc)()){
        bind(pfunc);
    }

    //! Class function 1 args constructor
    CFunctor2(R (*pfunc)(T0)){
        bind(pfunc);
    }
#	endif

    //! Class function 2 args constructor
    CFunctor2(R (*pfunc)(T0, T1)){
        bind(pfunc);
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class method 0 args constructor
    template<class C>
    CFunctor2(C *pclass, R (C::*pmethod)()){
        bind(pclass, pmethod);
    }

    //! Class function 1 args constructor
    template<class C>
    CFunctor2(C *pclass, R (C::*pmethod)(T0)){
        bind(pclass, pmethod);
    }
#	endif

    //! Class function 2 args constructor
    template<class C>
    CFunctor2(C *pclass, R (C::*pmethod)(T0, T1)){
        bind(pclass, pmethod);
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Assign function pointer 0 args
    TFunc0 operator=(R (*pfunc)()){
        bind(pfunc);
        return pfunc;
    }

    //! Assign function pointer 1 args
    TFunc1 operator=(R (*pfunc)(T0)){
        bind(pfunc);
        return pfunc;
    }
#	endif

    //! Assign function pointer 2 args
    TFunc2 operator=(R (*pfunc)(T0, T1)){
        bind(pfunc);
        return pfunc;
    }




    //! Compare with other functor
    inline bool operator==(const CFunctor2 &rhs)	const {
        return c==NULL ? (f.function2 == rhs.f.function2) : ((c == rhs.c) && (f.method2 == rhs.f.method2));
    }
#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Compare with function 0 args
    inline bool operator==(R (*pfunc)())	const {
        return c==NULL ? (f.function0 == pfunc) : false;
    }

    //! Compare with function 1 args
    inline bool operator==(R (*pfunc)(T0))	const {
        return c==NULL ? (f.function1 == pfunc) : false;
    }
#	endif

    //! Compare with function 2 args
    inline bool operator==(R (*pfunc)(T0, T1))	const {
        return c==NULL ? (f.function2 == pfunc) : false;
    }

    inline R operator()(const Arguments &args){
        return operator()(args.arg0, args.arg1);
    }

    //! Functor realization
    inline R operator()(T0 arg0, T1 arg1){
        if(c != NULL){
#			if USEFULHEADER_FUNCTORS_LEVEL == 1
                return ((c)->*(f.method2))(arg0, arg1);
#			elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return ((c)->*(f.method0))();
                    case 1: return ((c)->*(f.method1))(arg0);
                    case 2: return ((c)->*(f.method2))(arg0, arg1);
                };
#			endif
        }else if(f.function2 != NULL){
#			if USEFULHEADER_FUNCTORS_LEVEL == 1
                return f.function2(arg0, arg1);
#			elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return f.function0();
                    case 1: return f.function1(arg0);
                    case 2: return f.function2(arg0, arg1);
                };
#			endif
        }
        return R();
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to function of 0 arguments
    inline void bind(R (*pfunc)()){
        c = NULL;
        f.function0 = pfunc;
        num_args = 0;
    }

    //! Set pointer to function of 1 arguments
    inline void bind(R (*pfunc)(T0)){
        c = NULL;
        f.function1 = pfunc;
        num_args = 1;
    }
#	endif

    //! Set pointer to function of 2 arguments
    inline void bind(R (*pfunc)(T0, T1)){
        c = NULL;
        f.function2 = pfunc;
        #if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 2;
        #endif
    }



#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to method of 0 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)()){
        c = (TClass*)pclass;
        f.method0 = (TMethod0)pmethod;
        num_args = 0;
    }

    //! Set pointer to method of 1 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0)){
        c = (TClass*)pclass;
        f.method1 = (TMethod1)pmethod;
        num_args = 1;
    }
#	endif

    //! Set pointer to method of 2 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0, T1)){
        c = (TClass*)pclass;
        f.method2 = (TMethod2)pmethod;
#		if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 2;
#		endif
    }


    bool isBinded(){
        return f.method0 == NULL;
    }

    void reset(){
        c = NULL;
        f.method0 = NULL;
    }
};











/*!
 * Functor with tree arguments. @see CFunctor
 */
template<class T0, class T1, class T2, class R = void>
class CFunctor3 {
private:
    class TClass {};
    typedef R (TClass::*TMethod0)();
    typedef R (TClass::*TMethod1)(T0);
    typedef R (TClass::*TMethod2)(T0, T1);
    typedef R (TClass::*TMethod3)(T0, T1, T2);
    typedef R (*TFunc0)();
    typedef R (*TFunc1)(T0);
    typedef R (*TFunc2)(T0, T1);
    typedef R (*TFunc3)(T0, T1, T2);

    TClass *c;
    union{
        TFunc0	function0;
        TMethod0 method0;
        TFunc1	function1;
        TMethod1 method1;
        TFunc2	function2;
        TMethod2 method2;
        TFunc3	function3;
        TMethod3 method3;
    } f;
#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    char num_args;
#	endif

public:

    struct Arguments{
        T0 arg0;
        T1 arg1;
        T2 arg2;
    };


    //! Default constructor
    CFunctor3(){
        c = NULL;
        f.method3 = NULL;
        #if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = -1;
        #endif
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class function 0 args constructor
    CFunctor3(R (*pfunc)()){
        bind(pfunc);
    }

    //! Class function 1 args constructor
    CFunctor3(R (*pfunc)(T0)){
        bind(pfunc);
    }

    //! Class function 2 args constructor
    CFunctor3(R (*pfunc)(T0, T1)){
        bind(pfunc);
    }
#	endif

    //! Class function 3 args constructor
    CFunctor3(R (*pfunc)(T0, T1, T2)){
        bind(pfunc);
    }

#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Class method 0 args constructor
    template<class C>
    CFunctor3(C *pclass, R (C::*pmethod)()){
        bind(pclass, pmethod);
    }

    //! Class method 1 args constructor
    template<class C>
    CFunctor3(C *pclass, R (C::*pmethod)(T0)){
        bind(pclass, pmethod);
    }

    //! Class method 2 args constructor
    template<class C>
    CFunctor3(C *pclass, R (C::*pmethod)(T0, T1)){
        bind(pclass, pmethod);
    }
#	endif

    //! Class method 3 args constructor
    template<class C>
    CFunctor3(C *pclass, R (C::*pmethod)(T0, T1, T2)){
        bind(pclass, pmethod);
    }



#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Assign function pointer 0 args
    TFunc0 operator=(R (*pfunc)()){
        bind(pfunc);
        return pfunc;
    }

    //! Assign function pointer 1 args
    TFunc1 operator=(R (*pfunc)(T0)){
        bind(pfunc);
        return pfunc;
    }

    //! Assign function pointer 2 args
    TFunc2 operator=(R (*pfunc)(T0, T1)){
        bind(pfunc);
        return pfunc;
    }
#	endif

    //! Assign function pointer 3 args
    TFunc3 operator=(R (*pfunc)(T0, T1, T2)){
        bind(pfunc);
        return pfunc;
    }




    //! Compare with other functor
    inline bool operator==(const CFunctor3 &rhs) const {
        return c==NULL ? (f.function3 == rhs.f.function3) : ((c == rhs.c) && (f.method3 == rhs.f.method3));
    }
#if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Compare with function 0 args
    inline bool operator==(R (*pfunc)())	const {
        return c==NULL ? (f.function0 == pfunc) : false;
    }

    //! Compare with function 1 args
    inline bool operator==(R (*pfunc)(T0))	const {
        return c==NULL ? (f.function1 == pfunc) : false;
    }

    //! Compare with function 2 args
    inline bool operator==(R (*pfunc)(T0, T1))	const {
        return c==NULL ? (f.function2 == pfunc) : false;
    }
#	endif

    //! Compare with function 3 args
    inline bool operator==(R (*pfunc)(T0, T1, T2))	const {
        return c==NULL ? (f.function3 == pfunc) : false;
    }


    inline R operator()(const Arguments &args){
        return operator()(args.arg0, args.arg1, args.arg2);
    }


    //! Functor realization
    inline R operator()(T0 arg0, T1 arg1, T2 arg2){
        if(c != NULL){
#			if USEFULHEADER_FUNCTORS_LEVEL == 1
                return ((c)->*(f.method3))(arg0, arg1, arg2);
#			elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return ((c)->*(f.method0))();
                    case 1: return ((c)->*(f.method1))(arg0);
                    case 2: return ((c)->*(f.method2))(arg0, arg1);
                    case 3: return ((c)->*(f.method3))(arg0, arg1, arg2);
                };
#			endif
        }else if(f.function3 != NULL){
#			if USEFULHEADER_FUNCTORS_LEVEL == 1
                return f.function3(arg0, arg1, arg2);
#			elif USEFULHEADER_FUNCTORS_LEVEL >= 2
                switch(num_args){
                    case 0: return f.function0();
                    case 1: return f.function1(arg0);
                    case 2: return f.function2(arg0, arg1);
                    case 3: return f.function3(arg0, arg1, arg2);
                };
#			endif
        }
        return R();
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to function of 0 arguments
    inline void bind(R (*pfunc)()){
        c = NULL;
        f.function0 = pfunc;
        num_args = 0;
    }

    //! Set pointer to function of 1 arguments
    inline void bind(R (*pfunc)(T0)){
        c = NULL;
        f.function1 = pfunc;
        num_args = 1;
    }

    //! Set pointer to function of 2 arguments
    inline void bind(R (*pfunc)(T0, T1)){
        c = NULL;
        f.function2 = pfunc;
        num_args = 2;
    }
#	endif

    //! Set pointer to function of 3 arguments
    inline void bind(R (*pfunc)(T0, T1, T2)){
        c = NULL;
        f.function3 = pfunc;
        #if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 3;
        #endif
    }


#	if USEFULHEADER_FUNCTORS_LEVEL >= 2
    //! Set pointer to method of 0 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)()){
        c = (TClass*)pclass;
        f.method0 = (TMethod0)pmethod;
        num_args = 0;
    }

    //! Set pointer to method of 1 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0)){
        c = (TClass*)pclass;
        f.method1 = (TMethod1)pmethod;
        num_args = 1;
    }

    //! Set pointer to method of 2 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0, T1)){
        c = (TClass*)pclass;
        f.method2 = (TMethod2)pmethod;
        num_args = 2;
    }
#	endif

    //! Set pointer to method of 3 arguments
    template<class C>
    inline void bind(C *pclass, R (C::*pmethod)(T0, T1, T2)){
        c = (TClass*)pclass;
        f.method3 = (TMethod3)pmethod;
#		if USEFULHEADER_FUNCTORS_LEVEL >= 2
        num_args = 3;
#		endif
    }


    bool isBinded(){
        return f.method0 == NULL;
    }

    void reset(){
        c = NULL;
        f.method0 = NULL;
    }

};

































//! Class of TData32
class CData32 {
private:
    TData32 d;
public:

    inline operator TData32() const {return d;}
    inline operator bool() const {return d.bit.b0;}

#if CHAR_BIT == 8
    inline operator int8_t() const {return d.Vi8_;}
    inline operator uint8_t() const {return d.Vui8_;}
#endif

#if CHAR_BIT <= 16
    inline operator int16_t() const {return d.Vi16_;}
    inline operator uint16_t() const {return d.Vui16_;}
#endif

    inline operator int32_t() const {return d.Vi32;}
    inline operator uint32_t() const {return d.Vui32;}

    inline operator float32_t() const {return d.Vf32;}

    inline TData32 &operator()() {return d;}

    inline CData32() {d.Vui32 = 0;}
    inline ~CData32() {}

    inline CData32(const TData32 value) {d = value;}
    inline CData32(const bool value) {d.Vui32 = value;}
    inline CData32(const uint32_t value) {d.Vui32 = value;}
    inline CData32(const int32_t value) {d.Vi32 = value;}
    inline CData32(const float32_t value) {d.Vf32 = value;}
    inline CData32(const float64_t value) {d.Vf32 = (float32_t) value;}

    friend class CData64;
};







//! Class of TData64
class CData64 {
private:
    TData64 d;
public:

    inline operator TData64() const {return d;}
    inline operator bool() const {return d.bit.b0;}

#if CHAR_BIT == 8
    inline operator int8_t() const {return d.Vi8_;}
    inline operator uint8_t() const {return d.Vui8_;}
#endif

#if CHAR_BIT <= 16
    inline operator int16_t() const {return d.Vi16_;}
    inline operator uint16_t() const {return d.Vui16_;}
#endif

    inline operator int32_t() const {return d.Vi32_;}
    inline operator uint32_t() const {return d.Vui32_;}

    inline operator int64_t() const {return d.Vi64;}
    inline operator uint64_t() const {return d.Vui64;}

    inline operator float32_t() const {return d.Vf32_;}
    inline operator float64_t() const {return d.Vf64;}

    inline TData64 &operator()() {return d;}
    inline CData64 &operator=(const CData64 &value) {d.Vui64 = value.d.Vui64; return *this;}
    inline CData64 &operator=(const CData32 &value) {d.Vui64 = value.d.Vui32; return *this;}

    inline CData64() {d.Vui64 = 0;}
    inline ~CData64() {}

    inline CData64(const TData64 value) {d = value;}
    inline CData64(const bool value) {d.Vui64 = value;}
    inline CData64(const uint64_t value) {d.Vui64 = value;}
    inline CData64(const int64_t value) {d.Vi64 = value;}
    inline CData64(const uint32_t value) {d.Vui64 = value;}
    inline CData64(const int32_t value) {d.Vi64 = value;}
    inline CData64(const uint16_t value) {d.Vui64 = value;}
    inline CData64(const int16_t value) {d.Vi64 = value;}

#if CHAR_BIT == 8
    inline CData64(const uint8_t active) {d.Vui64 = active;}
    inline CData64(const int8_t active) {d.Vi64 = active;}
#endif
    inline CData64(const float32_t value) {d.Vf32_ = value;}
    inline CData64(const float64_t value) {d.Vf64 = value;}

    friend class CData32;
};












//! Enum variant types
enum EVariantType {
    vt_NaN = 0,
    vt_i8 = 	BIT(0),
    vt_ui8 = 	BIT(1),

    vt_i16 = 	BIT(2),
    vt_ui16 = 	BIT(3),

    vt_i32 = 	BIT(4),
    vt_ui32 = 	BIT(5),

    vt_i64 = 	BIT(6),
    vt_ui64 = 	BIT(7),

    vt_f32 = 	BIT(8),
    vt_f64 = 	BIT(9)
};




//! Variant up to 64-bit values
class CVariant64 {
protected:
    TData64 data;
    EVariantType type;
public:

    CVariant64() {
        data.Vui64 = 0;
        type = vt_NaN;
    }
    ~CVariant64() {
    }


    EVariantType Type() {
        return type;
    }


#if CHAR_BIT == 8
    CVariant64 &operator=(const int8_t active)
    {	data.Vi8[0] = active; type = vt_i8; return *this;}

    CVariant64 &operator=(const uint8_t active)
    {	data.Vui8[0] = active; type = vt_ui8; return *this;}
#endif

    CVariant64 &operator=(const int16_t value)  {
        data.Vi16_ = value;
        type = vt_i16;
        return *this;
    }

    CVariant64 &operator=(const uint16_t value)  {
        data.Vui16_ = value;
        type = vt_ui16;
        return *this;
    }

    CVariant64 &operator=(const int32_t value)  {
        data.Vi32_ = value;
        type = vt_i32;
        return *this;
    }

    CVariant64 &operator=(const uint32_t value)  {
        data.Vui32_ = value;
        type = vt_ui32;
        return *this;
    }

    CVariant64 &operator=(const int64_t &value)  {
        data.Vi64 = value;
        type = vt_i64;
        return *this;
    }

    CVariant64 &operator=(const uint64_t &value)  {
        data.Vui64 = value;
        type = vt_ui64;
        return *this;
    }

    CVariant64 &operator=(const float32_t value)  {
        data.Vf32_ = value;
        type = vt_f32;
        return *this;
    }

    CVariant64 &operator=(const float64_t value)  {
        data.Vf64 = value;
        type = vt_f64;
        return *this;
    }


    template<class T>
    operator T() const{
        return (T)*this;
    }


    operator int64_t() const {
        switch(type){
            case vt_i8: return data.Vi8_;
            case vt_ui8: return data.Vui8_;
            case vt_i16: return data.Vi16_;
            case vt_ui16: return data.Vui16_;
            case vt_i32: return data.Vi32_;
            case vt_ui32: return data.Vui32_;
            case vt_NaN: return 0;
            case vt_i64: return data.Vi64;
            case vt_ui64: return static_cast<int64_t>(data.Vui64);

            case vt_f32: return static_cast<int64_t>(data.Vf32_);
            case vt_f64: return static_cast<int64_t>(data.Vf64);
        }
        return 0;
    }


    operator uint64_t() const {
        switch(type){
            case vt_i8: return static_cast<uint64_t>(data.Vi8_);
            case vt_ui8: return data.Vui8_;
            case vt_i16: return static_cast<uint64_t>(data.Vi16_);
            case vt_ui16: return data.Vui16_;
            case vt_i32: return static_cast<uint64_t>(data.Vi32_);
            case vt_ui32: return data.Vui32_;
            case vt_NaN: return 0;
            case vt_i64: return static_cast<uint64_t>(data.Vi64);
            case vt_ui64: return static_cast<uint64_t>(data.Vui64);

            case vt_f32: return static_cast<uint64_t>(data.Vf32_);
            case vt_f64: return static_cast<uint64_t>(data.Vf64);
        }
        return 0;
    }


    operator int32_t() const {
        switch(type){
            case vt_i8: return data.Vi8_;
            case vt_ui8: return static_cast<int32_t>(data.Vui8_);
            case vt_i16: return data.Vi16_;
            case vt_ui16: return static_cast<int32_t>(data.Vui16_);
            case vt_NaN: return 0;
            case vt_i32: return data.Vi32_;
            case vt_ui32: return static_cast<int32_t>(data.Vui32_);
            case vt_i64: return static_cast<int32_t>(data.Vui64);
            case vt_ui64: return static_cast<int32_t>(data.Vui64);

            case vt_f32: return static_cast<int32_t>(data.Vf32_);
            case vt_f64: return static_cast<int32_t>(data.Vf64);
        }
        return 0;
    }


    operator uint32_t() const {
        switch(type){
            case vt_i8: return static_cast<uint32_t>(data.Vi8_);
            case vt_ui8: return data.Vui8_;
            case vt_i16: return static_cast<uint32_t>(data.Vi16_);
            case vt_ui16: return data.Vui16_;
            case vt_NaN: return 0;
            case vt_i32: return static_cast<uint32_t>(data.Vi32_);
            case vt_ui32: return data.Vui32_;
            case vt_i64: return static_cast<uint32_t>(data.Vi64);
            case vt_ui64: return static_cast<uint32_t>(data.Vui64);

            case vt_f32: return static_cast<uint32_t>(data.Vf32_);
            case vt_f64: return static_cast<uint32_t>(data.Vf64);
        }
        return 0;
    }


#if CHAR_BIT <= 16
    operator int16_t() const {
        switch(type){
            case vt_i8: return data.Vui8_;
            case vt_ui8: return static_cast<int16_t>(data.Vui8_);
            case vt_NaN: return 0;
            case vt_i16: return data.Vi16_;
            case vt_ui16: return static_cast<int16_t>(data.Vui16_);
            case vt_i32: return static_cast<int16_t>(data.Vi32_);
            case vt_ui32: return static_cast<int16_t>(data.Vui32_);
            case vt_i64: return static_cast<int16_t>(data.Vi64);
            case vt_ui64: return static_cast<int16_t>(data.Vui64);

            case vt_f32: return static_cast<int16_t>(data.Vf32_);
            case vt_f64: return static_cast<int16_t>(data.Vf64);
        }
        return 0;
    }

    operator uint16_t() const {
        switch(type){
            case vt_i8: return static_cast<uint16_t>(data.Vui8_);
            case vt_ui8: return data.Vui8_;
            case vt_NaN: return 0;
            case vt_i16: return static_cast<uint16_t>(data.Vi16_);
            case vt_ui16: return data.Vui16_;
            case vt_i32: return static_cast<uint16_t>(data.Vi32_);
            case vt_ui32: return static_cast<uint16_t>(data.Vui32_);
            case vt_i64: return static_cast<uint16_t>(data.Vi64);
            case vt_ui64: return static_cast<uint16_t>(data.Vui64);

            case vt_f32: return static_cast<uint16_t>(data.Vf32_);
            case vt_f64: return static_cast<uint16_t>(data.Vf64);
        }
        return 0;
    }
#endif



#if CHAR_BIT == 8
    operator int8_t() const {
        switch(type){
            case vt_NaN:
            case vt_i8: return data.Vi8_;
            case vt_ui8: return static_cast<int8_t>(data.Vui8_);
            case vt_i16: return static_cast<int8_t>(data.Vi16_);
            case vt_ui16: return static_cast<int8_t>(data.Vui16_);
            case vt_i32: return static_cast<int8_t>(data.Vi32_);
            case vt_ui32: return static_cast<int8_t>(data.Vui32_);
            case vt_i64: return static_cast<int8_t>(data.Vi64);
            case vt_ui64: return static_cast<int8_t>(data.Vui64);

            case vt_f32: return static_cast<int8_t>(data.Vf32_);
            case vt_f64: return static_cast<int8_t>(data.Vf64);
        }
        return 0;
    }

    operator uint8_t() const {
        switch(type){
            case vt_NaN:
            case vt_i8:
            case vt_ui8: return data.Vui8_;
            case vt_i16: return static_cast<uint8_t>(data.Vi16_);
            case vt_ui16: return static_cast<uint8_t>(data.Vui16_);
            case vt_i32: return static_cast<uint8_t>(data.Vi32_);
            case vt_ui32: return static_cast<uint8_t>(data.Vui32_);
            case vt_i64: return static_cast<uint8_t>(data.Vi64);
            case vt_ui64: return static_cast<uint8_t>(data.Vui64);

            case vt_f32: return static_cast<uint8_t>(data.Vf32_);
            case vt_f64: return static_cast<uint8_t>(data.Vf64);
        }
        return 0;
    }
#endif



    operator float32_t() const {
        switch(type){
            case vt_i8: return static_cast<float32_t>(data.Vi8_);
            case vt_ui8: return static_cast<float32_t>(data.Vui8_);
            case vt_i16: return static_cast<float32_t>(data.Vi16_);
            case vt_ui16: return static_cast<float32_t>(data.Vui16_);
            case vt_i32: return static_cast<float32_t>(data.Vi32_);
            case vt_ui32: return static_cast<float32_t>(data.Vui32_);
            case vt_i64: return static_cast<float32_t>(data.Vi64);
            case vt_ui64: return static_cast<float32_t>(data.Vui64);

            case vt_NaN: return 0.0;
            case vt_f32: return data.Vf32_;
            case vt_f64: return static_cast<float32_t>(data.Vf64);
        }
        return 0;
    }


    operator float64_t() const {
        switch(type){
            case vt_i8: return static_cast<float64_t>(data.Vi8_);
            case vt_ui8: return static_cast<float64_t>(data.Vui8_);
            case vt_i16: return static_cast<float64_t>(data.Vi16_);
            case vt_ui16: return static_cast<float64_t>(data.Vui16_);
            case vt_i32: return static_cast<float64_t>(data.Vi32_);
            case vt_ui32: return static_cast<float64_t>(data.Vui32_);
            case vt_i64: return static_cast<float64_t>(data.Vi64);
            case vt_ui64: return static_cast<float64_t>(data.Vui64);

            case vt_NaN: return 0.0;
            case vt_f32: return static_cast<float64_t>(data.Vf32_);
            case vt_f64: return data.Vf64;
        }
        return 0;
    }


};










template<class T>
class CBitWorker{
private:
    T *addr;
    T mask;
    T smask;
    char shift;
    char size;
public:

    CBitWorker(T &addr, char shift, char size){
        this->addr = &addr;
        setStruct(shift, size);
    }

    inline T &operator=(T &val){
        *addr = (*addr & smask) | ((val & mask) << shift);
        return val;
    }

    operator T() const {
        return (*addr >> shift) & mask;
    }

    void setStruct(char shift, char size){
        this->shift = shift;
        this->size = size;
        mask = (T(1) << size) - 1;
        smask = ~(mask << shift);
    }


};
















template<class T, class P>
class CUsefulPayload : public T{
public:

    CUsefulPayload()	{}
    virtual ~CUsefulPayload() {}

    P Payload;

};











//! Opperating with two area data: read-area which only maybe read, write-area which maybe read and write
template<class T>
class CMappedRW {
protected:
    T &read_loc;
    T &write_loc;
public:

    CMappedRW(T &read_location, T &write_location) :
        read_loc(read_location),
        write_loc(write_location)
    {
        read_loc = write_loc = 0;
    }

    ~CMappedRW(){}

    //! When setting data write to write_loc, but read_loc not used
    T &operator=(const T &value){
        write_loc = value;
    }


    //! When getting data, get it from read_loc
    inline operator T() const {
        return read_loc;
    }

    //! Read read_loc data
    inline T ValueRead(){
        return read_loc;
    }

    //! Read write_loc data
    inline T ValueWrite(){
        return write_loc;
    }

    //! Write operation from read_loc to write_loc
    inline bool write(){
        bool ret = (write_loc != read_loc);
        write_loc = read_loc;
        return ret;
    }

    //! Write operation from write_loc to read_loc
    inline bool read(){
        bool ret = (write_loc != read_loc);
        read_loc = write_loc;
        return ret;
    }

    //! If write and read locations are equal, return true
    inline bool isSyncronized(){
        return write_loc == read_loc;
    }

};











template<class T>
class CMappedValue {
protected:
    T active;
    T &mapped;
    T low;
    T hi;
public:

    CMappedValue(T &mapped_location) :
        mapped(mapped_location) {
        low = hi = active = T();
    }

    ~CMappedValue(){}

    T &operator=(const T &value){
        if(low != hi) 	active = CONSTRAIN(value, low, hi);
        else 			active = value;
        return active;
    }


    inline operator T() const {
        return active;
    }

    inline T &operator()(){
        return active;
    }

    inline T ValueActive(){
        return active;
    }

    inline T ValueMapped(){
        return mapped;
    }


    inline bool updateMapped(){
        bool ret = mapped != active;
        mapped = active;
        return ret;
    }

    inline bool updateActive(){
        bool ret;
        if(low != hi){
            T tmp = CONSTRAIN(mapped, low, hi);
            ret = tmp != active;
            active = tmp;
        }else{
            ret = mapped != active;
            active = mapped;
        }
        return ret;
    }


    inline T LevelLow(){
        return low;
    }

    inline T LevelHi(){
        return low;
    }


    inline void setConstrain(T low, T hi){
        this->low = low;
        this->hi = hi;
        if(low != hi){
            active = CONSTRAIN(active, low, hi);
        }
    }

    inline bool isSyncronized(){
        return mapped == active;
    }

};





























//! Fictive stack class
class CFicStack{
private:
    char *stack_base;
    char *stack;
public:

    CFicStack(void *stack_ptr){
        stack_base = stack = (char*)stack_ptr;
    }


    template<class T>
    void push(T &object){
        memcpy(stack, &object, sizeof(object));
        stack += sizeof(object);
    }

    template<class T>
    void pop(T &object){
        stack -= sizeof(object);
        memcpy(&object, stack, sizeof(object));
    }


    template<class T>
    inline void operator>>(T &object){
        pop(object);
    }

    template<class T>
    inline void operator<<(const T &object){
        push(object);
    }

    template<class T>
    friend inline void operator>>(const T &object, CFicStack &fstack);
    template<class T>
    friend inline void operator<<(T &object, CFicStack &fstack);

};

template<class T>
inline void operator<<(T &object, CFicStack &fstack){
    fstack.pop(object);
}


template<class T>
inline void operator>>(const T &object, CFicStack &fstack){
    fstack.push(object);
}












class CStackAllocator{
private:
    void *base;
    void *curr;
    size_t size;
public:

    CStackAllocator(void *base = nullptr, size_t size = 0){setMemory(base, size);}
    ~CStackAllocator(){}

    inline void setMemory(void *base, size_t size)	{this->base = curr = base; this->size = size;}

    template<class T>
    T *allocate(size_t count = 1){
        // Aligning
        curr = (void*)(((size_t)curr + (__alignof(T)-1)) & ~(__alignof(T)-1));
        T *ret = (T*)curr;
        curr = (void*)((size_t)curr + sizeof(T)*count);
        new(curr) T[count];
        return ret;
    }

    inline size_t Offset()				{return (size_t)curr - (size_t)base;}
    inline void setOffset(size_t value)	{curr = (void*)((size_t)base + value);}

    inline size_t Remain()				{return size - Offset();}

};






























#if USEFULHEADER_PROPERTIES_LEVEL >= 1

//! Property start declaration
#define PROPERTY_DECL(class_name, prop_type)	\
class { \
private: \
    typedef class_name TClass; \
    typedef prop_type TPropType; \
public:


//! Property getter declaration with user-specified name of getter method1
#define PROPERTY_GETTER(prop_name, getter_name)	\
public: inline operator TPropType() const{	\
    return baseptr(TClass, prop_name, this)->getter_name(); \
}


//! Property getter declaration with auto-generated name of getter method1
#define PROPERTY_AGETTER(prop_name)	\
public: inline operator TPropType() const{	\
    return baseptr(TClass, prop_name, this)->get_##prop_name(); \
}


//! Property setter declaration with user-specified name of setter method1
#define PROPERTY_SETTER(prop_name, setter_name)	\
public: inline TPropType operator=(const TPropType &value){	\
    baseptr(TClass, prop_name, this)->setter_name(value);	\
    return value;\
}

//! Property setter declaration with auto-generated name of setter method1
#define PROPERTY_ASETTER(prop_name)	\
public: inline TPropType operator=(const TPropType &value){	\
    baseptr(TClass, prop_name, this)->set_##prop_name(value);	\
    return value; \
}



/*
//! Property operation plus declaration with user-specified name of operator method1
#define PROPERTY_PLUS(prop_name, op_name)	\
public: inline TPropType operator+(const TPropType &value) const{	\
    return baseptr(TClass, prop_name, this)->op_name(value); \
}


//! Property operation minus declaration with user-specified name of operator method1
#define PROPERTY_MINUS(prop_name, op_name)	\
public: inline TPropType operator-(const TPropType &value) const{	\
    return baseptr(TClass, prop_name, this)->op_name(value); \
}


//! Property operation mult declaration with user-specified name of operator method1
#define PROPERTY_MULT(prop_name, op_name)	\
public: inline TPropType operator*(const TPropType &value) const{	\
    return baseptr(TClass, prop_name, this)->op_name(value); \
}


//! Property operation div declaration with user-specified name of operator method1
#define PROPERTY_DIV(prop_name, op_name)	\
public: inline TPropType operator/(const TPropType &value) const{	\
    return baseptr(TClass, prop_name, this)->op_name(value); \
}


//! Property operation mod declaration with user-specified name of operator method1
#define PROPERTY_MOD(prop_name, op_name)	\
public: inline TPropType operator%(const TPropType &value) const{	\
    return baseptr(TClass, prop_name, this)->op_name(value); \
}
*/

//! Property create object
#define PROPERTY_CREATE(prop_name)	\
} prop_name;


//! Fast declaration read/write property. Use auto-named methods get_##prop_name and set_##prop_name, or PROPERTY_GETTER_CREATE and PROPERTY_SETTER_CREATE
#define PROPERTY_RW_FASTDECL(class_name, prop_name, prop_type) PROPERTY_DECL(class_name, prop_type) PROPERTY_AGETTER(prop_name) PROPERTY_ASETTER(prop_name) PROPERTY_CREATE(prop_name)
//! Fast declaration read-only property. Use auto-named method1 get_##prop_name, or macro PROPERTY_GETTER_CREATE
#define PROPERTY_R_FASTDECL(class_name, prop_name, prop_type) PROPERTY_DECL(class_name, prop_type) PROPERTY_AGETTER(prop_name) PROPERTY_CREATE(prop_name)
//! Fast declaration write-only property. Use auto-named method1 set_##prop_name, or macro PROPERTY_SETTER_CREATE
#define PROPERTY_W_FASTDECL(class_name, prop_name, prop_type) PROPERTY_DECL(class_name, prop_type) PROPERTY_ASETTER(prop_name) PROPERTY_CREATE(prop_name)


//! Property getter create. Maybe implementation here
#define PROPERTY_GETTER_CREATE(prop_name, prop_type)	\
prop_type get_##prop_name() const

//! Property setter create. Maybe implementation here
#define PROPERTY_SETTER_CREATE(prop_name, prop_type)	\
void set_##prop_name(const prop_type& value)




//! Property getter implementation outside class
#define PROPERTY_GETTER_IMPL(class_name, prop_name, prop_type)	\
prop_type class_name::get_##prop_name() const

//! Property setter implementation outside class
#define PROPERTY_SETTER_IMPL(class_name, prop_name, prop_type)	\
void class_name::set_##prop_name(const prop_type& value)




/* Code Example

class CFrame{
private:
    int w, h;
    float32_t scale;

    PROPERTY_SETTER_CREATE(Width, int){w = value;}
    PROPERTY_GETTER_CREATE(Width, int){return w;}

    PROPERTY_SETTER_CREATE(Height, int){h = value;}
    PROPERTY_GETTER_CREATE(Height, int){return h;}

    PROPERTY_SETTER_CREATE(Scale, float32_t){scale = value;}
    PROPERTY_GETTER_CREATE(Scale, float32_t){return scale;}

public:

    PROPERTY_DECL(CFrame, int)
    PROPERTY_ASETTER(Width)
    PROPERTY_AGETTER(Width)
    PROPERTY_CREATE(Width)

    PROPERTY_DECL(CFrame, int)
    PROPERTY_ASETTER(Height)
    PROPERTY_AGETTER(Height)
    PROPERTY_CREATE(Height)

    PROPERTY_DECL(CFrame, float32_t)
    PROPERTY_ASETTER(Scale)
    PROPERTY_AGETTER(Scale)
    PROPERTY_CREATE(Scale)

};




CFrame fr;


int main(int argc, char *argv[]){

    fr.Scale = 4.0/3.0;					// fr.scale == 1.33333333
    fr.Height = 45;						// fr.h == 45
    fr.Width = fr.Height * fr.Scale;	// fr.w == 60

    int w,h;
    float32_t s;

    w = fr.Width;						// w == 60
    h = fr.Height;						// h == 45
    s = fr.Scale;						// s == 1.33333333

    return 0;
}




*/

#endif	//if properties





































#if USEFULHEADER_STATEMACHINE_LEVEL >= 1



/*!
 * Declaration states keyword
 * example:
 * @code
 * STATES_DECLARATION{
 * 		STATE_DECL(state0)
 * 		STATE_DECL(state1)
 * 		STATE_DECL(state2)
 * 		STATE_DECL(state3)
 * };
 * @endcode
 *
 */
#define STATES_DECLARATION	\
public: enum EState

/*!
 * See STATES_DECLARATION
 */
#define STATE_DECL(statename)	\
    statename,




/*!
 * Start implementation statemachine
 */
#define STATEMACHINE_BEGIN_THIS(sm)	\
{ \
    typedef typeof(sm)	__statemachine_guts_local_t; \
    __statemachine_guts_local_t &__statemachine_guts = sm; \
    typedef struct {} __statemachine_guts_context_t;



#define STATEMACHINE_END_THIS	\
}



#define STATEMACHINE_IMPLEMENT 	\
__label_statemachine_implementation:	\
    if(__statemachine_guts.stack_top->prestate == 0)	\
        __statemachine_guts.stack_top->prestate = -1;	\
    else	\
    switch (__statemachine_guts.stack_top->curr_state)


/*!
 * Anyone state implementation
 */
#define STATE_IMPLEMENT(statename)	\
    break;	\
    __statemachine_guts_label_top_##statename: \
    case __statemachine_guts_local_t::statename :

/*!
 * State ENTRY implemenatation
 */
#define STATE_ENTRY	\
    while(1){	\
        switch(__statemachine_guts.stack_top->instate){	\
            case 0:{


/*!
 * State EXECUTION implemenatation
 */
#define STATE_EXEC	\
                __statemachine_guts.stack_top->instate = 1;	\
            } \
            case 1:{


/*!
 * State EXIT implemenatation
 */
#define STATE_EXIT	\
                break;	\
            }	\
            case 2:{	\


/*!
 * Terminator of state implementation
 */
#define STATE_END	\
                __statemachine_guts.stack_top->curr_state = __statemachine_guts.stack_top->next_state;	\
                __statemachine_guts.stack_top->instate = 0;	\
            } \
        }; \
        break;	\
    };//while



/*!
 * Break executing state. Not destroy state.
 */
#define STATE_BREAK()	\
    do{	\
        __statemachine_guts.stack_top->prestate = 0;	\
        goto __label_statemachine_implementation;	\
    }while(0);



/*!
 * Change state. If execute this macro, then next state changed, in current tick
 * program go to state EXIT, and leave function. In next tick program go to
 * state ENTRY there next state.
 */
#define STATE_CHANGE(statename)	\
    {	\
        __statemachine_guts.stack_top->next_state = __statemachine_guts_local_t::statename;	\
        __statemachine_guts.stack_top->instate = 2;	\
        __statemachine_guts.stack_top->stage = 0;	\
        goto __label_statemachine_implementation;	\
    }


/*!
 * Set state in statemachine. In next tick go to state ENTRY. Calling maybe anywhere
 */
#define STATE_SET(statename)	\
    {	\
        __statemachine_guts.stack_top->next_state = __statemachine_guts_local_t::statename;	\
        __statemachine_guts.stack_top->instate = 0;	\
        __statemachine_guts.stack_top->stage = 0;	\
    }

/*!
 * Increment stack top, and go to new specified state. In current stack top
 * state not go to state EXIT, but freeze, and when return to this state work
 * continue normaly.
 */
#define STATE_CALL(statename)	\
    if(__statemachine_guts.stack_level < (sizeof(__statemachine_guts.stack)/sizeof(*__statemachine_guts.stack))-1){	\
        __statemachine_guts.stack_level++;	\
        __statemachine_guts.stack_top++;	\
        __statemachine_guts.stack_top->curr_state = __statemachine_guts_local_t::statename;	\
        __statemachine_guts.stack_top->next_state = __statemachine_guts_local_t::statename;	\
        __statemachine_guts.stack_top->instate = 0;	\
        __statemachine_guts.stack_top->stage = 0;	\
        goto __label_statemachine_implementation;	\
    }

/*!
 * Returning to bottom level stack, and work normal from last state saved
 */
#define STATE_RETURN()	\
    {	\
        if(__statemachine_guts.stack_level > 0){	\
            __statemachine_guts.stack_level--;	\
            __statemachine_guts.stack_top--;	\
        }else{	\
            __statemachine_guts.stack_top->curr_state = __statemachine_guts.init_state;	\
            __statemachine_guts.stack_top->next_state = __statemachine_guts.init_state;	\
            __statemachine_guts.stack_top->instate = 0;	\
        }	\
        __statemachine_guts.stack_top->prestate = 0;	\
        goto __label_statemachine_implementation;	\
    }



#define STATE_PAUSE(num_iters)	\
        __statemachine_guts.pause_cnt = num_iters;




#define STATE_CONTEXTYPE(type) \
    typedef type __statemachine_guts_context_t;


/*!
 * Access to current stack level context
 */
#define STATE_CONTEXT	\
    (*(__statemachine_guts_context_t*)__statemachine_guts.stack_top->context)



#define STAGES	\
    switch(__statemachine_guts.stack_top->stage)

#define STAGE_DEFAULT	\
    default:

#define STAGE(num)	\
    break;	\
    case num :

#define STAGE_CHANGE(num)	\
    __statemachine_guts.stack_top->stage = num;









/*!
 * Guts of collective structure of statemachine for sequencing variabled :)
 */
template<int depth = 1, int SS = sizeof(char)*CHAR_SIZE>
class CStatemachineGuts {
public:

    struct TStateContext {
        int curr_state;
        int next_state;
        int stage;
        short instate : 4;
        short prestate : 4;
        char context[SS/CHAR_SIZE];
    };

    long pause_cnt;
    int init_state;

    TStateContext stack[depth];
    TStateContext *stack_top;
    int stack_level;

    CStatemachineGuts(){
        init_state = 0;
        stack_level = 0;
        pause_cnt = 0;
        stack_top = stack;
        stack[0].next_state = stack[0].curr_state = init_state;
        stack[0].instate = 0;
    }

    CStatemachineGuts(int init_state){
        this->init_state = init_state;
        stack_level = 0;
        pause_cnt = 0;
        stack_top = stack;
        stack[0].next_state = stack[0].curr_state = init_state;
        stack[0].instate = 0;
    }
};



/*!
 * Basic class for working with statemachine.
 * For example minimal code:
 * @code
 *
 *	class SM_MyStatemachine : public CStatemachine<5, TMyContext>{
 *
 *		int a,b,c;
 *
 *		STATES_DECLARATION{
 *			STATE_DECL(state1)
 *			STATE_DECL(state2)
 *			STATE_DECL(state3)
 *		};
 *
 *
 *	public:
 *
 *		void someFunctionHandler(){
 *
 *			STATEMACHINE_SPACE_BEGIN(sm)
 *
 *			STATEMACHINE_IMPLEMENT{
 *
 *				STATE_IMPLEMENT(state1){
 *					STATE_ENTRY
 *						a = 0;
 *					STATE_EXEC
 *						if(a++ > 5)
 *						STATE_CHANGE(state2);
 *					STATE_EXIT
 *
 *					STATE_END
 *				};
 *
 *
 *				STATE_IMPLEMENT(state2){
 *					STATE_ENTRY
 *						a = 0;
 *						b = 0;
 *					STATE_EXEC
                        c += a + b;
                        a++;
                        b++;
                        if(c > 1000000)
                            STATE_CHANGE(state1)
                        if(c > 100)
                            STATE_CHANGE(state3);
 *					STATE_EXIT
 *
 *					STATE_END
 *				};
 *
 *
 *				STATE_IMPLEMENT(state3){
 *					STATE_ENTRY
 *						a = 0;
 *						b = 0;
 *					STATE_EXEC
 *						c *= 1 + a + b;
 *						if(c > 1000)
 *							STATE_CHANGE(state2);
 *					STATE_EXIT
 *
 *					STATE_END
 *				};
 *
 *			};
 *
 *			STATEMACHINE_SPACE_END()
 *
 *		};
 *
 *	};
 *
 *
 * @endcode
 */



#endif	//Statemachine block















































#endif	//if __cplusplus

#endif
