/******************************************************************************\
********************************************************************************
**                                                                            **
**                  [ V N K  -  V I N A  K N O W L E D G E ]                  **
**                                                                            **
**                   SITE  : https://www.vinaknowledge.com                    **
**                   EMAIL : hvloi@vinaknowledge.com                          **
**                                                                            **
**                        TAN BINH DST, HCMC, VIET NAM                        **
**                                                                            **
**                 Copyright © 2019-2020 VNK - Vina Knowledge                 **
**                                                                            **
********************************************************************************
\******************************************************************************/

/******************************************************************************\
*******************************I*N*C*L*U*D*E*S**********************************
\******************************************************************************/

/**
 * Global Includes
 **/

#include <stdio.h>
#include <string.h>
#include <getopt.h>

/**
 * V N K - Includes
 **/

#include "VNK_LinuxSocketExample.h"
#include "VNK_VNKSOC_Utilities.h"

/******************************************************************************\
****************************D*E*F*I*N*I*T*I*O*N*S*******************************
\******************************************************************************/

/******************************************************************************\
********************************G*L*O*B*A*L*S***********************************
\******************************************************************************/

/******************************************************************************\
********************************P*R*I*V*A*T*E***********************************
\******************************************************************************/

/**
 * ShowHelp
 * Description:
 * - Showing Help
 **/
static void ShowHelp();

/**
 * CheckNonOptionArgs
 * Description:
 * - Check if there is any no-option argument
 **/
static void CheckNonOptionArgs(int c_argc, int c_optind, char* argv[]);

/******************************************************************************\
*******************************M*A*I*N*C*O*D*E**********************************
\******************************************************************************/

/**
 * Parsing Command Line Arguments
 **/
int OptsParsing(int argc, char *argv[], vnksoc_config *config)
{
    int RetCode, c;
    char server[] = "server";
    char client[] = "client";

    if(argc <= 1)
    {
        vnk_info_notify("Oop! No error, but argument is needed!");
        vnk_info_notify(">> type \"%s --help\" for help!", argv[0]);
    }

    while(EVER)
    {
        /* Index of an option in long_options */
        int option_index = 0;

        static struct option long_options[] =
        {
            {"role",    required_argument,    NULL,    'r'},
            {"help",    no_argument,          NULL,    'h'},
            {NULL,      0,                    NULL,     0 }
        };

        c = getopt_long(argc, argv, "r:h", long_options, &option_index);

        /* Check if there is nothing to parse */
        if (c == -1)
        {
            break; // Break loop
        }

        switch (c)
        {
            case 'r':
                if(strncmp(server, optarg, sizeof(server)) == 0)
                {
                    config->IsServer = true;
                }
                else
                if (strncmp(client, optarg, sizeof(client)) == 0)
                {
                    config->IsServer = false;
                }
                else
                {
                    vnk_error_notify(NO_ERRNO, "Unknown role \"%s\"!", optarg);
                    RetCode = RETURN_FAILURE;
                    goto EndPoint;
                }
                break;

            case 'h':
                ShowHelp();
                break;

            case '?':
                break;

            default:
                vnk_info_notify("Oop! Something wrong!");
                break;
        }
    }

    /* Check non-option arguments */
    CheckNonOptionArgs(argc, optind, argv);

EndPoint:

    return RetCode;
}

/**
 * ShowHelp
 * Description:
 * - Showing Help
 **/
static void ShowHelp()
{
    printf("VNK - UNIX Domain Socket Example\n");
    printf("-----------------------------------------\n\n");

    printf("Usage:\n\n");

    printf("    --role,-r <role>\n");
    printf("    Role, \"server\" or \"client\".\n\n");

    printf("    --help,-h\n");
    printf("    Help, show this help.\n\n");

    printf("-----------------------------------------\n");

    return;
}

/**
 * CheckNonOptionArgs
 * Description:
 * - Check if there is any no-option argument
 **/
static void CheckNonOptionArgs(int c_argc, int c_optind, char* argv[])
{
    if(c_argc > c_optind)
    {
        vnk_info_notify("There are some non-option argument:");
        printf("        ");
        while(c_optind < c_argc)
        {
            printf("%s ", argv[c_optind++]);
        }
        printf("\n");
    }

    return;
}

/**
 * Preparing Utilities For Socket
 * Note:
 * - r_*: indicate references
 **/
int PrepareSocket(int *r_soc_fd, struct sockaddr_un *r_addr)
{
    /* Return code */
    int RetCode;

    /* Open UNIX domain socket */
    *r_soc_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(*r_soc_fd == -1)
    {
        /* errno is set if error */
        vnk_error_notify(errno, "socket()");
        RetCode = RETURN_FAILURE;
        goto EndPoint;
    }

    memset(r_addr, 0, sizeof(struct sockaddr_un));

    r_addr->sun_family = AF_UNIX;

    strncpy(r_addr->sun_path, SOC_PATH, sizeof(r_addr->sun_path) - 1);

EndPoint:

    return RetCode;
}

/******************************************************************************\
************************************E*N*D***************************************
\******************************************************************************/