//Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your 
//project #1.  The program contains some errors and it is not designed to be efficient. 
//Modify the program to make it better and efficient.  Explain in your report how you have modified the
//program to make it better.

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
   */
bool checker = false;
/*  conclusion list */ 
string conclt[8]; 
/*  variable list */ 
string varlt[20]; 
/*  clause vairable list */ 
string clvarlt[200]; 
string varble; 
string /* clauses */ FE, WL, UR, SB, BU, BS, TI, NL, TS, LA, 
       /* clauses */ CU, UB, VO, BL, FU, LN, HO, VC, NT; 
string /* possible cancer */ PC = "YES", /* has cancer */ NC, KC, HCL, TC, BC, GC; 

/* instantiated list */ 
int instlt[33]; 
/* statement stack */ 
int statsk[33]; 
int /* clause stack */ clausk[33], sn = 0, f, i, j, s, k, /*stack pointer */ sp; 

void determine_member_concl_list(void); 
void push_on_stack(void); 
void instantiate(void); 
void block1();
void block2();

int main() 
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
        
        for (i=1; i<41; i++)  clvarlt[i] = ""; 

        conclt[1] = "NC"; //no cancer 
        conclt[2] = "PC"; //possible cancer
        conclt[3] = "KC"; //kidney cancer 
        conclt[4] = "HCL"; //hairy cell leukemia
        conclt[5] = "TC"; //thyroid cancer 
        conclt[6] = "BC"; //bladder cancer 
        conclt[7] = "GC"; //gastric cancer 
        printf("*** CONCLUSION LIST ***\n"); 
        for (i=1; i<8; i++) 
           //printf("CONCLUSION %d %s\n", i, conclt[i]); 
           cout << "CONCLUSION " << i << ": " << conclt[i] << endl;

        cout << "HIT RETURN TO CONTINUE"; 
        getchar();
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
        varlt[12] = "UB"; //urinating burns
        varlt[13] = "VO"; //vomiting and stomach pain
        varlt[14] = "BL"; //bloated
        varlt[15] = "FU"; //feels full
        varlt[16] = "LN"; //swollen lymph nodes
        varlt[17] = "HO"; //hoarseness
        varlt[18] = "VC"; //voice change
        varlt[19] = "NT"; //pain to neck and throat
        for(i=1; i<20; i++) //printf("VARIABLE %d %s\n", i, varlt[i]); 
        cout << "VARIABLE " << i << ": " << varlt[i] << endl;
        cout << "HIT RETURN KEY TO CONTINUE"; 
        getchar();
        /* enter variables as they appear in the if clauses.  a maximum 
        of 3 
        variables per if statement.  if no more variables hit return 
        key. */ 
        cout << "*** CLAUSE VARIABLE LIST ***\n"; 
        /***** comment 407 through 409 ***/ 
        //strcpy(clvarlt[1], "DE"); 
        clvarlt[1] = "FE";
        clvarlt[5] = "FE";
        clvarlt[9] = "FE";
        clvarlt[13] = "WL";
        clvarlt[17] = "WL";
        clvarlt[21] = "SB";
        clvarlt[25] = "SB";
        clvarlt[29] = "TI";
        clvarlt[33] = "TI";
        clvarlt[37] = "TI";
        clvarlt[41] = "NL";
        clvarlt[45] = "TS";
        clvarlt[49] = "TS";
        clvarlt[53] = "TS";
        clvarlt[57] = "VO";
        clvarlt[61] = "VO";
        clvarlt[65] = "BL";
        clvarlt[69] = "FU";
        clvarlt[73] = "LN";
        clvarlt[77] = "HO";
        clvarlt[81] = "VC";
        clvarlt[85] = "NT";
        clvarlt[89] = "UR";
        clvarlt[93] = "UR";
        clvarlt[97] = "BU";
        clvarlt[101] = "BU";
        clvarlt[105] = "BS";
        clvarlt[109] = "BS";
        clvarlt[113] = "BS";
        clvarlt[117] = "LA";
        clvarlt[121] = "CU";
        clvarlt[125] = "UB";
         
        for(i=1; i<9; i++) 
        { 
                cout << "** CLAUSE " << i << endl; 
                for(j=1; j<5; j++) 
                { k = 4 * (i-1) + j; 
                  //cout << "VARIABLE %d  %s\n", j, clvarlt[k]; 
                  cout << "VARIABLE " << j << ": " << clvarlt[k] << endl;
                } 
                if (i==4) 
                { 
                   cout << "HIT RETURN KEY TO CONTINUE"; 
                   getchar(); 
                } 
        } 
        /****** inference section *****/ 
        cout << "** ENTER CONCLUSION ? "; 
        cin >> varble; 
        /* get conclusion statement number (sn) from the conclusion list 
           (conclt) */ 
        /* first statement starts search */ 
        block1();
} 

void block1()
{ 
          f=1; 
          determine_member_concl_list(); 
          if (sn != 0){ 
                block2();
          } 
}

void block2()
{
        /* if sn = 0 then no conclusion of that name */ do 
                  /* push statement number (sn) and clause number=1 on 
                     goal 
                     stack which is composed of the statement stack 
                     (statsk) 
                     and clause stack (clausk) */ 
                  { 
                          if(checker == true) push_on_stack(); 
                          do 
                          { 
                           /* calculate clause location in clause-variable 
                              list */ 
          i= (statsk[sp] -1) *4 + clausk[sp]; 
          /* clause variable */ 
          //strcpy(varble, clvarlt[i]); 
          varble = clvarlt[i];
          if(varble != "") { 
                  /*is this clause variable a conclusion? */ 
                  f = 1; 
                  determine_member_concl_list(); 
                  if(sn != 0) 
                          /* it is a conclusion push it */ 
                          checker = true;
                          block1(); 
                  /* check instantiation of this clause */ 
                  instantiate(); 
                  clausk[sp] = clausk[sp] + 1; 
          } 
                          } while(varble != ""); /*do-while*/ 
                          /*no more clauses check if part of statement */ 
                          sn = statsk[sp]; 
                          s = 0; 
                          /**** if then statements ****/ 
                          /* sample if parts of if then statements from 
                             the position knowledge base */ 
                          switch (sn) { 
                                  /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 1: if(FE == "NO") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 2: if(FE == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 3: if(PC == "YES") s = 1;
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 4: if(WL == "NO") s = 1;
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 5: if(WL == "YES") s = 1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 6: if(SB == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 7: if(SB == "NO") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 8: if((TI == "YES") && 
                                     (SB == "YES")) s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 9: if(TI == "NO") s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 10: if((NL == "YES") && 
                                      (TI == "YES")) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 11: if((TI == "YES") && 
                                      (SB == "YES")) s = 1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 12: if(TS == "NO") s = 1;
                                  break;  
                                  /****** comment 1500 ****/ 
                          case 13: if(TS == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 14: if((VO == "YES")  &&
                                      (TS == "YES")) s =1; 
                                  break; 
                             
                          case 15: if(VO == "NO") s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 16: if(BL == "YES") s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 17: if((BL == "YES") &&
                                      (FU == "YES")) s =1;
                                  break; 
                                  /* if part of statement 6 */ 
                          case 18: if(TS == "YES") s = 1;
                                  break; 
                                                      /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 19: if(LN == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 20: if((HO == "YES") && 
                                      (LN == "YES")) s =1;
                                  break; 
                                  /* if part of statement 3 */ 
                          case 21: if(VC == "YES") s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 22: if((NT == "YES") && 
                                      (VC == "YES")) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 23: if(FE == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 6 */ 
                          case 24: if(PC == "YES") s = 1;
                                  break; 
                                                      /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 25: if(UR == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 26: if(UR == "NO")s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 27: if((BU == "YES") && 
                                     (UR == "YES")) s =1; 
                                  break; 
                                  /* if part of statement 4 */ 
                                  /******** comment 1560 ******/ 
                          case 28: if((BS == "YES") && 
                                      (BU == "NO")) s = 1; 
                                  break; 
                                  /******** comment 1570 ********/ 
                                  /* if part of statement 5 */ 
                          case 29: if(BS == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 6 */ 
                          case 30: if((LA == "YES") && 
                                      (BS == "YES")) s = 1;
                                  break;                       /* if part of statement 1 */ 
                                  /****** comment 1500 ****/ 
                          case 31: if(BS == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 2 */ 
                                  /***** comment 1510 ******/ 
                          case 32: if(CU == "YES") s = 1; 
                                  break; 
                                  /* if part of statement 3 */ 
                          case 33: if(UB == "YES") s =1; 
                                  break;
                          } 
                          /* see if the then part should be invoked */ 
                          if( s != 1) { 
                                  /* failed..search rest of statements for 
                                     same conclusion */ 
                                  /* get conclusion */ 
                                  i = statsk[sp]; 
                                  //strcpy(varble, conclt[i]); 
                                  varble = conclt[i];
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
                          case 1: NC = "YES"; 
                                  cout << "NO CANCER\n"; 
                                  break; 
                          case 2: PC = "YES"; 
                                  cout << "PC=YES\n"; 
                                  break; 
                          case 3: WL = "YES"; 
                                  cout << "WL=YES\n"; 
                                  break; 
                          case 4: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break; 
                          case 5: SB = "YES";
                                  cout << "SB=YES"; 
                                  break; 
                          case 6: TI = "YES"; 
                                  cout << "TI=YES\n"; 
                                  break;
                          case 7: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break; 
                          case 8: NL = "YES"; 
                                  cout << "NL=YES\n"; 
                                  break; 
                          case 9: NC = "YES"; 
                                  cout << "NO CANCER\n"; 
                                  break; 
                         case 10: HCL = "YES";
                                  cout << "HAIRY CELL LEUKEMIA\n"; 
                                  break; 
                         case 11: TS = "YES";
                                  cout << "TS=YES"; 
                                  break; 
                         case 12: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break;   
                         case 13: VO = "YES";
                                  cout << "VO=YES\n"; 
                                  break; 
                         case 14: BL = "YES";
                                  cout << "BL=YES\n"; 
                                  break; 
                         case 15: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break; 
                         case 16: FU = "YES";
                                  cout << "FU=YES\n"; 
                                  break; 
                         case 17: GC = "YES";
                                  cout << "GASTRIC CANCER"; 
                                  break; 
                         case 18: LN = "YES";
                                  cout << "LN=YES\n"; 
                                  break;
                         case 19: HO = "YES";
                                  cout << "HO=YES\n"; 
                                  break;
                         case 20: VC = "YES";
                                  cout << "VC=YES\n"; 
                                  break; 
                         case 21: NT = "YES";
                                  cout << "NT=YES\n"; 
                                  break; 
                         case 22: TC = "YES";
                                  cout << "THYROID CANCER\n"; 
                                  break; 
                         case 23: PC = "YES"; 
                                  cout << "PC=YES\n"; 
                                  break; 
                         case 24: UR = "YES";
                                  cout << "UR=YES"; 
                                  break;
                         case 25: BU = "YES";
                                  cout << "BU=YES\n"; 
                                  break;
                         case 26: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break; 
                         case 27: BS = "YES";
                                  cout << "BS=YES\n"; 
                                  break;
                         case 28: NC = "YES";
                                  cout << "NO CANCER\n"; 
                                  break; 
                         case 29: LA = "YES";
                                  cout << "LA=YES\n"; 
                                  break; 
                         case 30: KC = "YES"; 
                                  cout << "KIDNEY CANCER\n"; 
                                  break; 
                         case 31: CU = "YES";
                                  cout << "CU=YES"; 
                                  break;  
                         case 32: UB = "YES";
                                  cout << "UB=YES\n"; 
                                  break; 
                         case 33: BC = "YES"; 
                                  cout << "BLADDER CANCER\n"; 
                                  break;       
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
                                  checker = false;
                                  cout << "looping 2";
                                  block2(); 
                          } 
                  } 
}

void determine_member_concl_list() { 
/* routine to determine if a variable (varble) is a member of the 
   conclusion list (conclt).  if yes return sn != 0. 
   if not a member sn=0; 
*/ 
        sn = 0;

        for (int i = 1; i < 8; i++)
        {
            if(varble == conclt[i])
                sn = i;
        } 
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
        while((varble != varlt[i]) && (i<20)) i=i+1; 
        if((varble == varlt[i]) && (instlt[i] != 1)) 
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
                case 1: printf("INPUT YES OR NO FOR FEVER: "); 
                        cin >> FE; 
                        break; 
                case 2: printf("INPUT YES OR NO FOR WEIGHT LOSS: "); 
                        cin >> WL; 
                        break; 
                case 3: printf("INPUT YES OR NO FOR FREQUENT URINATION: "); 
                        cin >> UR; 
                        break; 
                case 4: printf("INPUT YES OR NO FOR SHORTNESS OF BREATH: "); 
                        cin >> SB; 
                        break;  
                case 5: printf("INPUT YES OR NO FOR BLOOD IN URINE: "); 
                        cin >> BU; 
                        break;  
                case 6: printf("INPUT YES OR NO FOR BACK/SIDE PAIN: "); 
                        cin >> BS; 
                        break;  
                case 7: printf("INPUT YES OR NO FOR TIREDNESS: "); 
                        cin >> TI; 
                        break;  
                case 8: printf("INPUT YES OR NO FOR NECK LUMPS: "); 
                        cin >> NL; 
                        break;     
                case 9: printf("INPUT YES OR NO FOR TROUBLE SWALLOWING: "); 
                        cin >> TS; 
                        break; 
                case 10: printf("INPUT YES OR NO FOR LOSS OF APPETITE: "); 
                        cin >> LA; 
                        break; 
                case 11: printf("INPUT YES OR NO FOR TROUBLE URINATING: "); 
                        cin >> CU; 
                        break; 
                case 12: printf("INPUT YES OR NO FOR BURNING URINATION: "); 
                        cin >> UB; 
                        break;  
                case 13: printf("INPUT YES OR NO FOR VOMITING/STOMACH PAIN: "); 
                        cin >> VO; 
                        break;  
                case 14: printf("INPUT YES OR NO FOR BLOATING: "); 
                        cin >> BL; 
                        break;  
                case 15: printf("INPUT YES OR NO FOR FEELING FULL: "); 
                        cin >> FU; 
                        break;  
                case 16: printf("INPUT YES OR NO FOR SWOLLEN LYMPH NODES: "); 
                        cin >> LN; 
                        break;     
                case 17: printf("INPUT YES OR NO FOR HOARSENESS: "); 
                        cin >> HO; 
                        break; 
                case 18: printf("INPUT YES OR NO FOR CHANGE IN VOICE: "); 
                        cin >> VC; 
                        break; 
                case 19: printf("INPUT YES OR NO FOR NECK/THROAT PAIN: "); 
                        cin >> NT; 
                        break;    
                } 
                /* end of inputs statements for sample position knowledge 
                   base */ 
        } 
} 