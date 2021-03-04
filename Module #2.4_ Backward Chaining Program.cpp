Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your 
project #1.  The program contains some errors and it is not designed to be efficient. 
Modify the program to make it better and efficient.  Explain in your report how you have modified the
program to make it better.

#include <iostream>
#include <string>

using namespace std;

/*****backward chaining *******/ 
/* Install your IF clauses in sequence in the first case 
   statement of the main program 
   example: if((a1==2) && (a2==6)) s=1; 
                      if(strcmp(j,NO") != 0) s=1; 
   the then part of the above construction always 
   contains s=1; 
   install your the clauses in sequence in the second 
   case statement of the main program 
   example strcpy(po,"YES"); 


/*  conclusion list */ 
string conclt[10]; 
/*  variable list */ 
string varlt[20]; 
/*  clause vairable list */ 
string clvarlt[40]; 
char varble[3]; 
char /* qualify */ qu[4], /* degree*/ de[4]; 
char /* discovery */ di[4], /* position */ po[4]; 
char buff[128]; 

/* instantiated list */ 
int instlt[11]; 
/* statement stack */ 
int statsk[11]; 
int /* clause stack */ clausk[11], sn, f, i, j, s, k, /*stack pointer */ sp; 

float /* grade */ gr, /*experience */ ex; 

void determine_member_concl_list(void); 
void push_on_stack(void); 
void instantiate(void); 

main() 
{ 
        /***** initialization section ******/ 
        /* stack space is 10 we initially place stack space at 10+1 */ 
        sp=11; 
        for (i=1; i<11; i++) 
        { 
                //strcpy(conclt[i],""); 
                //strcpy(varlt[i],""); 
                conclt[i] = "";
                varlt[i] = "";
                instlt[i]=0; 
                statsk[i]=0; 
                clausk[i]=0; 
        } 
        for (i=1; i<41; i++)  strcpy(clvarlt[i],""); 
        /* enter conclusions which are the variables in the then part, 
1 at 
        a time.  enter the conclusions in exact order starting at the 1st 
        if-then.  after last conclusion hit return key for rest of 
        conclusions */ 

        /*** comment 305 *****/ 
        conclt[1] = "NC"; //no cancer 
        conclt[2] = "KC"; //kidney cancer 
        conclt[3] = "HCL"; //hairy cell leukemia
        conclt[4] = "TC"; //thyroid cancer 
        conclt[5] = "BC"; //bladder cancer 
        conclt[6] = "GC"; //gastric cancer 
        printf("*** CONCLUSION LIST ***\n"); 
        for (i=1; i<11; i++) 
           cout << "CONCLUSION %d %s\n", i, conclt[i]; 

        cout << "HIT RETURN TO CONTINUE"; 
        
        /* enter variables which are in the if part, 1 at a time in the 
        exact 
        order that they occur, up to 3 variables per if statement.  do not 
        duplicate any variable names.  any name is used only once.  if no 
        more variables left just hit return key. */ 
        cout << "*** VARIABLE LIST *\n"; 
        /**** comment 367 *****/ 
        varlt[1] = "FE"; //fever
        varlt[2] = "WL"; //weight loss
        varlt[3] = "UR"; //frequently urinate
        varlt[4] = "SB"; //shortness of breath
        varlt[5] = "BU"; //blood in urine
        varlt[6] = "BS"; //back/side pain
        varlt[7] = "TI"; //tiredness
        varlt[8] = "NL"; //neck lumps
        varlt[9] = "TS"; //trouble swallowing
        varlt[10] = "LA"; //loss of appetite
        varlt[11] = "CU"; // can't urinate
        varlt[12]= "UB"; //urinating burns
        varlt[13] = "VO"; //vomiting and stomach pain
        varlt[14] = "BL"; //bloated
        varlt[15] = "FU"; //feels full
        varlt[16] = "LN"; //swollen lymph nodes
        varlt[17] = "HO"; //hoarseness
        varlt[18] = "VC"; //voice change
        varlt[19] = "NT"; //pain to neck and throat
        varlt[19] = "PC"; //possible cancer
        for(i=1; i<11; i++) printf("VARIABLE %d %s\n", i, varlt[i]); 
        cout << "HIT RETURN KEY TO CONTINUE"; 
        cin >> buff;
        /* enter variables as they appear in the if clauses.  a maximum 
        of 3 
        variables per if statement.  if no more variables hit return 
        key. */ 
        cout << "*** CLAUSE VARIABLE LIST ***\n"; 
        /***** comment 407 through 409 ***/ 
        //strcpy(clvarlt[1], "DE"); 
        clvart[1] = "FE";
         
        for(i=1; i<9; i++) 
        { 
                cout << "** CLAUSE %d\n", i; 
                for(j=1; j<5; j++) 
                { k = 4 * (i-1) + j; 
                  cout << "VARIABLE %d  %s\n", j, clvarlt[k]); 
                } 
                if (i==4) 
                { 
                   cout << "HIT RETURN KEY TO CONTINUE"; 
                   cin >> buff; 
                } 
        } 
        /****** inference section *****/ 
        cout << "** ENTER CONCLUSION ? "; 
        cin >> varble; 
        /* get conclusion statement number (sn) from the conclusion list 
           (conclt) */ 
        /* first statement starts search */ 
b520: f=1; 
          determine_member_concl_list(); 
          if (sn != 0){ 
                  /* if sn = 0 then no conclusion of that name */ do 
                  /* push statement number (sn) and clause number=1 on 
                     goal 
                     stack which is composed of the statement stack 
                     (statsk) 
                     and clause stack (clausk) */ 
                  { 
                          push_on_stack(); 
                          do 
                          { 
                           /* calculate clause location in clause-variable 
                              list */ 
b545: i= (statsk[sp] -1) *4 + clausk[sp]; 
          /* clause variable */ 
          strcpy(varble, clvarlt[i]); 
          if(strcmp(varble, "") != 0) { 
                  /*is this clause variable a conclusion? */ 
                  f = 1; 
                  determine_member_concl_list(); 
                  if(sn != 0) 
                          /* it is a conclusion push it */ 
                          goto b520; 
                  /* check instantiation of this clause */ 
                  instantiate(); 
                  clausk[sp] = clausk[sp] + 1; 
          } 
                          } while(strcmp(varble, "") != 0); /*do-while*/ 
                          /*no more clauses check if part of statement */ 
                          sn = statsk[sp]; 
                          s = 0; 
                          /**** if then statements ****/ 
                          /* sample if parts of if then statements from 
                             the position knowledge base */ 
                          switch (sn) { 
                                  /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 1: if(strcmp(FE, "NO") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 2: if(strcmp(FE, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 3: if(strcmp(PC, "YES") == 0) s = 1;
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 4: if(strcmp(WL, "NO") == 0) s = 1;
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 5: if(strcmp(WL, "YES") == 0) s = 1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 6: if(strcmp(SB, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 7: if(strcmp(SB, "NO") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 8: if((strcmp(TI, "YES") == 0) && 
                                     (strcmp(SB, "YES") == 0)) s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 9: if(strcmp(TI, "NO") == 0) s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 10: if((strcmp(NL, "YES") == 0) && 
                                      (strcmp(TI, "YES") == 0)) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 11: if((strcmp(TI, "YES") == 0) && 
                                      (strcmp(SB, "YES") == 0)) s = 1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 12: if(strcmp(TS, "NO") == 0) s = 1;
                                  break;  
                                  /****** comment 1500 ****/ 
                          case 13: if(strcmp(TS, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 14: if((strcmp(VO, "YES") == 0) &&
                                      (strcmp(TS, "YES") == 0)) s =1; 
                                  break; 
                             
                          case 15: if(strcmp(VO, "NO") == 0) s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 16: if(strcmp(BL, "YES") == 0) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 17: if((strcmp(BL, "YES") == 0) &&
                                      (strcmp(FU, "YES") == 0)) s =1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 18: if(strcmp(TS, "YES") == 0) s = 1;
                                  break; 
                                                      /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 19: if(strcmp(LN, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 20: if((strcmp(HO, "YES") == 0) && 
                                      (strcmp(LN, "YES") == 0)) s =1;
                                  break; 
                                  /* if part of statement 3 */ 
                          case 21: if(strcmp(VC, "YES") == 0) s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 22: if((strcmp(NT, "YES") == 0) && 
                                      (strcmp(VC, "YES") == 0)) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 23: if(strcmp(FE, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 6 */ 
                          case 24: if(strcmp(PC, "YES") == 0) s = 1;
                                  break; 
                                                      /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 25: if(strcmp(UR, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 26: if(strcmp(UR, "NO") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 27: if((strcmp(BU, "YES") == 0) && 
                                     (strcmp(UR, "YES") == 0)) s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 28: if((strcmp(BS, "YES") == 0) && 
                                      (strcmp(BU, "NO") == 0)) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 29: if(strcmp(BS, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 6 */ 
                          case 30: if((strcmp(LA, "YES") == 0) && 
                                      (strcmp(BS, "YES") == 0)) s = 1;
                                  break;                       /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 31: if(strcmp(BS, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 32: if(strcmp(CU, "YES") == 0) s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 33: if(strcmp(UB, "YES") == 0) s =1; 
                                  break;
                          } 
                          /* see if the then part should be invoked */ 
                          if( s != 1) { 
                                  /* failed..search rest of statements for 
                                     same conclusion */ 
                                  /* get conclusion */ 
                                  i = statsk[sp]; 
                                  strcpy(varble, conclt[i]); 
                                  /* search for conclusion starting at the 
                                     next statement number */ 
                                  f = statsk[sp] + 1; 
                                  determine_member_concl_list(); 
                                  sp = sp+1; 
                          } 
                          /* pop old conclusion and put on new one */ 
                  } while((s != 1) && (sn !=0));  /* outer do-while loop */ 
                  if(sn != 0){ 
                          /* if part true invoke then part */ 
                          /* then part of if-then statements from the 
                             position knowledge base */ 
                          switch (sn) { 
                                  /* then part of statement 1 */ 
                                  /******* comment 1500 *******/ 
                          case 1: strcpy(po, "NO"); 
                                  printf("PO=NO\n"); 
                                  break; 
                                  /* then part of statement 2 */ 
                                  /****** comment 1510 ******/ 
                          case 2: strcpy(qu, "YES"); 
                                  printf("QU=YES\n"); 
                                  break; 
                                  /* then part of statement 3 */ 
                          case 3: strcpy(po, "YES"); 
                                  printf("PO=RESEARCH\n"); 
                                  break; 
                                  /* then part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 4: strcpy(po, "YES"); 
                                  printf("PO=SERVICE ENGINEER\n"); 
                                  break; 
                                  /* then part of statement 5 */ 
                                  /****** comment 1570 *****/ 
                          case 5: strcpy(po, "NO"); 
                                  printf("PO=NO"); 
                                  break; 
                                  /* then part of statement 6 */ 
                          case 6: strcpy(po, "YES"); 
                                  printf("PO=PRODUCT ENGINEER\n"); 
                                  break;  
                                  /****** comment 1680 ********/ 
                          } 
                          /* pop the stack */ 
                          sp=sp+1; 
                          if(sp >= 11) 
                                  /* finished */ 
                                  printf("*** SUCCESS\n"); 
                          else { 
                                  /* stack is not empty */ 
                                  /* get next clause then continue */ 
                                  clausk[sp] = clausk[sp]+1; 
                                  goto b545; 
                          } 
                  } 
        } 
} 

void determine_member_concl_list() { 
/* routine to determine if a variable (varble) is a member of the 
   conclusion list (conclt).  if yes return sn != 0. 
   if not a member sn=0; 
*/ 
        /* initially set to not a member */ 
        sn = 0; 
        /* member of conclusion list to be searched is f */ 
        i = f; 
        while((strcmp(varble, conclt[i]) != 0) && (i<8)) 
                /* test for membership */ 
                i=i+1; 
        if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */ 
} 

void push_on_stack() 
/* routine to push statement number (sn) and a clause number of 1 onto the 
conclusion stack which consists of the statement stack (statsk) and the 
clause stack (clausk)..to push decrement stack pointer (sp) */ 
{ 
        sp=sp-1; 
        statsk[sp] = sn; 
        clausk[sp] = 1; 
} 

void instantiate() 
/* routine to instantiate a variable (varble) if it isn't already.  the 
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the 
variable list (varlt) contains the variable (varble). */ 
{ 
        i=1; 
        /* find variable in the list */ 
        while((strcmp(varble, varlt[i]) != 0) && (i<10)) i=i+1; 
        if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1)) 
                /*found variable and not already instantiated */ 
        { 
                instlt[i]=1; /*mark instantiated */ 
                /* the designer of the 
               knowledge base places the input statements to 
               instantiate the variables below in the case statement */ 
                switch (i) 
                { 
                        /***** input statement *****/ 
                        /* input statements for sample position knowledge 
                           base */ 
                        /***** comment 1700 ******/ 
                case 1: printf("INPUT YES OR NOW FOR DE-? "); 
                        cin >> de; 
                        break; 
                case 2: printf("INPUT YES OR NO FOR DI-? "); 
                        cin >> di; 
                        break; 
                case 3: printf("INPUT A REAL NUMBER FOR EX-? "); 
                        scanf("%f", &ex); 
                        break; 
                case 4: printf("INPUT A REAL NUMBER FOR GR-? "); 
                        scanf("%f", &gr); 
                        break; 
                        /***** comment 1715 ****/ 
                } 
                /* end of inputs statements for sample position knowledge 
                   base */ 
        } 
} 



