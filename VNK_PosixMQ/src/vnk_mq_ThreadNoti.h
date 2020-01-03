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

#ifndef VNK_MQ_THREAD_NOTI_H
#define VNK_MQ_THREAD_NOTI_H

/******************************************************************************\
*******************************I*N*C*L*U*D*E*S**********************************
\******************************************************************************/

/**
 * Local includes
 **/
#include "vnk_mq_poxis.h"


/******************************************************************************\
****************************D*E*F*I*N*I*T*I*O*N*S*******************************
\******************************************************************************/

/******************************************************************************\
********************************G*L*O*B*A*L*S***********************************
\******************************************************************************/

/******************************************************************************\
********************************P*R*I*V*A*T*E***********************************
\******************************************************************************/

/******************************************************************************\
*******************************M*A*I*N*C*O*D*E**********************************
\******************************************************************************/

/**
 * FUNCTION    :
 * VNK_ThreadNotification
 *
 * SCOPE       :
 * Global
 *
 * DESCRIPTION :
 *
 * INPUT       :
 *
 * OUTPUT      :
 *
 * NOTE        :
 * c_vnkmq_config: c means copy, passing copy of struct to fucntion.
 *
 **/
int VNK_ThreadNotification(struct vnkmq_config c_vnkmq_config);

/******************************************************************************\
************************************E*N*D***************************************
\******************************************************************************/

#endif // VNK_MQ_THREAD_NOTI_H //