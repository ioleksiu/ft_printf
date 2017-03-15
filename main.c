/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:43:53 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 19:10:46 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{
    //ft_printf("\n|%x|\n", 4294967296);
    //printf("|%x|", 4294967296);
    ft_printf("|%x|\n", -42);
    printf("|%x|\n", -42);
    return 0;
}
/*    int n;
    //char *d = "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*";
    //SITE CHECK//
    //printf("\n%s!\n", (NULL));
//    ft_printf("%s!", NULL);
    //
   // printf("\n%u",ft_printf("%s",d));
    //ft_printf("%s", "helloworld!");
    /*printf("hello%n",&n);
    printf("\n%d",n);
    printf("\n------------\n");
    ft_printf("hello%n",&n);
    ft_printf("\n%d",n);
    printf("\n==================\n");
    ft_printf("\n%5+d", 42);
    printf("\n%5+d", 42);
    printf("\n==================\n");
    //ft_printf("\n%0+5d", 42);
    //printf("\n%0+5d", 42);
    ft_printf("[%5.d %5.0d]\n", 0, 0);
    printf("[%5.d %5.0d]\n", 0, 0);
     */
    //printf("\n/////////////////////////////////////////////////////\n");
    //ft_printf("\n%#08x", 42);
    //printf("\n%#08x", 42);
    //ft_printf("\n%-15x", 542);
   // printf("\n%-15x", 542);
    //ft_printf("%#-08x", 42);
    //ft_printf("\n%#8x", 42);
    //printf("\n%#8x", 42);
    //ft_printf("|%-05o|", 2500);
    //ft_printf("%x", -42);
    //ft_printf("\n%15.4d", -42);
   // printf("\n%15.4d", -42);
    //ft_printf("\n%#6o", 2500);
    //printf("\n%#6o", 2500);
    //ft_printf("|%-+10.5d|", 4242);
    //printf("\n|%-+10.5d|", 4242);
    //ft_printf("\n|%+10.5d|", 4242);
    //printf("\n|%+10.5d|", 4242);
    //ft_printf("\n|%5+d|", -42);
    //printf("\n|%5+d|", -42);
    //ft_printf("\n%.0p", NULL);
    //printf("\n%+5p", NULL);
    //printf("\n%zu\n",18446744071562067968);
    //ft_printf("\n%zu",18446744071562067968);
   // ft_printf("%x", -42);
    //ft_printf("\n%x", -42);
    //printf("\n%x", -42);
    //printf("\n%-5.10o", 2500);
  //  return 0;

//}
//int main(int ac, char **av) {
    //va_list va;

  //  if (ac > 1) {
       // char *d = "work!";
    //    (void) ac;
/*
       printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello %%%.0+ 40s %s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("Hello %%%.0+ 40s %s","word!", "ama hero"));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello %%%.0+ 1s%s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("Hello %%%.0+ 1s%s","word!", "ama hero"));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("%.0+ 12  %Hello%%%.5+ 12  %%s%.200  23s %.0 10 - c","world!", "ama hero",'c'));
        printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("%.0+ 12  %Hello%%%.5+ 12  %%s%.200  23s %.0 10 - c","world!", "ama hero",'c'));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("%.15 3s","HELLO");
        printf("\n----------\n");
        ft_printf("%.15 3s","HELLO");
        */
        /*
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello%%%.+ 0 -10s %s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello%%%.+ 0 -10s %s","word!", "ama hero"));
        printf("\n=============\n");
        */
         /*
        printf("original : %0100 19s","hello");
        printf("\n");
        ft_printf("nriginal : %0100 19s","hello");
        printf("\n");
        printf("%3.5 -5k");
        printf("\n");
        ft_printf("%3.5 -5k");
        printf("\n=============\n");
        printf("original : %0-100 19s","hello");
        printf("\n");
        ft_printf("nriginal : %0-100 19s","hello");
        printf("\n");
        printf("Hello%%%0+23243-234-.3434");
        printf("\n");
        ft_printf("Hello%%%0+23243-234-.3434");


        printf("\n------------------\n");
        printf("%-.5 VV v");
        printf("\n------------------\n");
        ft_printf("%-.5 VV v\n");


        printf("%.2s","567");
        printf("\n--------------------\n");
        ft_printf("%.2s","567");

        ft_printf("|%c|", 131);
*/
        /*
         * printf("\n PRESS TEST \n");
        ft_printf("|% 4.5i|\n",42);
        ft_printf("|%4.5i|\n",42);
        ft_printf("|% 5.4i|\n",42);
        ft_printf("|%5.4i|\n",42);
        ft_printf("|%04.5i|\n",42);
        ft_printf("|%04.3i|\n",42);
        ft_printf("|%04.2i|\n",42);
        printf("\n ORIGINAL \n");
        printf("|% 4.5i|\n",42);
        printf("|%4.5i|\n",42);
        printf("|% 5.4i|\n",42);
        printf("|%5.4i|\n",42);
        printf("|%04.5i|\n",42);
        printf("|%04.3i|\n",42);
        printf("|%04.2i|\n",42);

         */
        //ft_printf("|%04i|\n", 42);
        //ft_printf("|%05i|\n", 42);
        //ft_printf("|%0i|\n", 42);
       // ft_printf("|%+i|\n", 42);
        //ft_printf("|%+d|\n", 42);
        //ft_printf("|%+i|\n", -42);
        //ft_printf("|%+04d|\n", 42);
        //ft_printf("\n|%d|\n",184);
       // printf("\n", 0 - 1);
        //printf("\n|%+ 020.14s|\n","HelloWorld");
        //ft_printf("\n|%+ 020.14s|\n","HelloWorld");
        //ft_printf("%zu\n",18446744071562067968);
        //printf("%zu\n", 18446744071562067968);
       // ft_printf("%lu", "-42");
        //printf("\n%lu", "-42");
//

    //ft_printf("%x\n", 4294959296);
  //  }
    //return (0);
//}
