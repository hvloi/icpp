/******************************************************************************\
********************************************************************************
**                                                                            **
**                  [ V N K - V I N A  K N O W L E D G E ]                    **
**                                                                            **
**                   SITE  : https://www.vinaknowledge.com                    **
**                   EMAIL : hvloi@vinaknowledge.com                          **
**                                                                            **
**                       TAN BINH DST, HCMC, VIET NAM                         **
**                                                                            **
**                      Copyright © 2019 Vina Knowledge                       **
**                                                                            **
********************************************************************************
\******************************************************************************/

/******************************************************************************\
*******************************I*N*C*L*U*D*E*S**********************************
\******************************************************************************/

/**
 * Standard Libraries.
 **/
#include <stdio.h>

/**
 * VNK API Includes, these includes, if the project is a library, can be API to
 * use the library.
 **/
#include "VNK_TemplateModule.h"

/**
 * VNK Local Include, these includes will be placed in the same folder with
 * source, in library concept, these include cannot be used as API.
 **/
 #include "VNK_TemplateModule_Local.h"

/******************************************************************************\
****************************D*E*F*I*N*I*T*I*O*N*S*******************************
\******************************************************************************/

#define WC          "V N K  -  T E M P L A T E  M O D U L E"

/******************************************************************************\
********************************G*L*O*B*A*L*S***********************************
\******************************************************************************/

/******************************************************************************\
********************************P*R*I*V*A*T*E***********************************
\******************************************************************************/

/******************************************************************************\
*******************************M*A*I*N*C*O*D*E**********************************
\******************************************************************************/

int main(int argc, char *argv[])
{
    vnk_info_notify("%s", WC);

    /* Some Code There */

    vnk_info_notify("%s done, exiting...", argv[0]);
    return RETURN_SUCCESS;
}

/******************************************************************************\
************************************E*N*D***************************************
\******************************************************************************/
