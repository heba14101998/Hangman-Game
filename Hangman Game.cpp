/*
|---------------------------------------------------------|
|                 **our first project**                   |
|                   **Hangman Game**                      |
|    Benha faculty of electrical engineering department   |
|                number of team members=7                 |
|                all member from section=8                |
|                     Date : 9/4/2018                     |  
|---------------------------------------------------------|
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int     score=0;                  //Initialization score counter .
int     wrong=0;                  //Initialization wrong letter counter .
char    Continue ;                //Continue playing.
void    introduction ();          //Func TO print introduction.
void    startGame(int,int&);      //Func TO starting game.
string  country ();               //Func TO stored countries' names.
char    InputLetter () ;          //Func TO allowed the user to enter a letter .
void    letterPostions (char,string,int,char []); //Func TO putting letter in his positions.
void    check (bool,bool,char [],string,int);              
int main()
{  
     char start , confirm;string name ;
     introduction();
     cin>>start;
     if (start =='Y' || start=='y')            //if starting (enter 'Y' or 'y').
     {  cout <<setw(10)<<" "<<"Let's starting \n";
     	cout<<"plz enter Your name : ";
        cin>>name;
        startGame(score,wrong);}
     else if(start !='Y' || start!='y')        //enter any other char .
     {
	 cout<<setw(5)<<" "<<" are you sure about ending the game \n"
	     <<setw(5)<<" "<<"enter 'C' or 'c' to quite and 'N' or 'n' to Continue \n";
	 cin >>confirm ;
	 if (confirm == 'S' || confirm== 's')
     cout<<setw(5)<<" "<<"you end the game -_-\n";
     else if (confirm== 'N' || confirm== 'n')
	 {   cout <<setw(10)<<" "<<"Let's starting \n";
	        startGame(score,wrong);}
	 }
    return 0;
}
//------------------------------------------------------------------------------
void introduction (){
    cout<<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|     Welcome to Hangman          |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|               O                 |\n"
        <<setw(50)<<"|              /|\\                |\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|              / \\                |\n"
        <<setw(50)<<"|         +----------+            |\n"
        <<setw(50)<<"|         |          |            |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|        Available letters        |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|     A B C D E F G H I J K L M   |\n"
        <<setw(50)<<"|     N O P Q R S T U V W X Y Z   |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|         Guess the word          |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<endl
        <<setw(36)<<"~Rules~\n"
        <<setw(36)<<"<1> You should guess the correct countries For each correct answer,\n"
        <<setw(36)<<"    your score increases by one rate ^_^  .\n\n"
        <<setw(36)<<"<2> if you Make 5 wrong letters you will dead ^_^ .\n\n"
		<<setw(36)<<"<3> click on 'Y' or 'y' to start playing \n"
		<<setw(20)<<"    any other char to quite.\n";
}
//------------------------------------------------------------------------------
 void startGame (int score ,int &wrong )
 {  string word;        //the country passed to user.
    int length;         //the length of the country passed.
    char passWord[10];  //the word appears to the user .
    cout<<setw(5)<<" "<<"=>Your initial score : "<<score<<" points "<<endl;
    //NOTE:always wrong=0 when starting or Continue.
    wrong=0;
    cout<<setw(5)<<" "<<"=>Your initial wrong tries : "<<wrong<<endl;
      word=country();
      length = word.length();
	  cout<<setw(29)<<"Guess this country ^_^\n\n"<<setw(25)<<" ";
	  for (int i=0;i<length;++i)
	 	  {passWord[i]='_';
	       cout<<passWord[i]<<' ';}
	       cout<<endl<<endl;
    cout<<setw(5) <<" "<<"guess a letter : "; 
    letterPostions(InputLetter (), word, length,passWord);
}
//------------------------------------------------------------------------------
string country ()
   {  //countries name array .
    string country [] ={"EGYPT"    , "ALGERIA" , "YEMEN"    , "OMAN"    , "QATAR" , "LIBYA"   ,
                        "SUDAN"    , "KUWAIT"  , "SOMALIA"  , "BRAZIL"  , "SYRIA" , "LEBANON" ,
                    	"IRAQ"     , "MOROCCO" , "TUNISIA"  , "SPAIN"   , "CHINA" , "INDIA"   ,
                        "FRANCE"   , "ISRAEL"  };
                int i = rand ()%19;   //20 is the number of countries.
                return country[i];
                    	
   }
//------------------------------------------------------------------------------
char InputLetter ()
   {   char letter ;                //letter passed by user.
	   cin>>letter;
       letter = toupper (letter);   //using upper letter only.
	   return letter ;
   }
//------------------------------------------------------------------------------
void letterPostions (char letter,string country,int length,char passWord[])
   { 
      bool chackWrong= false ;         //check is the guessed letter wrong?
      bool chackRight= false ;         //check is the guessed letter right?
       for (int i=0;i<length;i++)
		 // if the guessed letter is right.
         if (letter == country[i])
         {passWord[i]=letter;          //replacing '_'by the right letter .
          chackRight=true;
          chackWrong=false;
         }
       check ( chackRight , chackWrong , passWord ,country,  length );
       // if the guessed letter is wrong .
       for (int i=0;i<length;i++)
	 	 if (letter != country[i])
	    	{
         	 chackWrong=true;
             chackRight=false;
            }
		 
       check (chackRight,chackWrong,passWord,country,length);
    }
//-----------------------------------------------------------------------------------
void check (bool chackRight,bool chackWrong,char passWord[],string country,int length)
{   // show the word after the true letter and enter another letter.	 
     if (chackWrong==false && chackRight==true )  
	    { 
	     int equal=0;
	     for(int i=0;i<length;i++)
	     //if the user guessed all the letters .
   		 if(passWord[i]==country[i])  
   		        equal++;
   			
	        if (equal==length)
	            { score++;
	              cout<<endl<<setw(5)<<" "<<"the country was  "<<country
	                  <<endl<<setw(5)<<" "<<"Congratulations !! you pass the test...\n"
	                  <<setw(10)<<" "<<"=>Your score is "<<score<<" points ^_^\n"
	                  <<setw(10)<<" "<<"=>You entered "<<wrong<<" wrong letter in this country name\n"
                      <<setw(10)<<" "<<"if you want to Continue playing..plz enter 'Y' or 'y'\n"
			          <<setw(10)<<" "<<"if don't enter 'N' or 'n' \n";
			       cin>>Continue;
	              if (Continue == 'Y' || Continue=='y' )
                     {cout<<setw(5)<<" "<<"Let's continue playing \n";
			   	           	startGame (score,wrong);}
	                   else exit(0);
	            }
	     //if the user not guessed all the letters  .
	     else 
	      {
          cout<<setw(25)<<" ";
	      for (int j=0;j<length;++j)
	      cout<<passWord[j]<<' ';
	      cout<<endl<<setw(5)<<" "<<"guess again :";
          letterPostions(InputLetter(),country,length,passWord);
	      }
	         
	   }
	         
	         
	 else if (chackWrong==true && chackRight==false ) 
	 {            ++wrong;
		  if (wrong==1) //nested if.
        {   //the first wrong letter.
        cout<<endl
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|          +===========+          |\n"
        <<setw(50)<<"|          |           |          |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(50)<<"|    Be careful you will Die -_-  |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(5)<<" "<<"guess again :";
            letterPostions(InputLetter(),country,length,passWord);
         }

          else if (wrong==2) 
        {   //the second wrong letter.
        cout<<endl
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                O                |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|          +===========+          |\n"
        <<setw(50)<<"|          |           |          |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(50)<<"|    Be careful you will Die -_-  |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<endl;
            cout<<setw(5)<<" "<<"guess again :";
            letterPostions(InputLetter(),country,length,passWord);
         }
         
          else if (wrong==3) 
        {   //the third wrong letter.
        cout<<endl
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                O                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|          +===========+          |\n"
        <<setw(50)<<"|          |           |          |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(50)<<"|    Be careful you will Die -_-  |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(5)<<" "<<"guess again :";
            letterPostions(InputLetter(),country,length,passWord);
        }
        
          else if (wrong==4) 
        {   //the fourth wrong letter.
        cout<<endl
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                O                |\n"
        <<setw(50)<<"|               /|\\               |\n"
        <<setw(50)<<"|                |                |\n"
        <<setw(50)<<"|                                 |\n"
        <<setw(50)<<"|          +===========+          |\n"
        <<setw(50)<<"|          |           |          |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(50)<<"|    Be careful you will Die -_-  |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(5)<<" "<<"guess again :";
            letterPostions(InputLetter(),country,length,passWord);
         }

         else if (wrong==5)
         { //the fifth wrong letter.
              cout<<endl
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|               O                 |\n"
        <<setw(50)<<"|              /|\\                |\n"
        <<setw(50)<<"|               |                 |\n"
        <<setw(50)<<"|              / \\                |\n"
        <<setw(50)<<"|         +==========+            |\n"
        <<setw(50)<<"|         |          |            |\n"
        <<setw(50)<<"+---------------------------------+\n"
		<<setw(50)<<"| another wrong and you will Dead |\n"
        <<setw(50)<<"+---------------------------------+\n"
        <<setw(10)<<" "<<"guess again :";
            letterPostions(InputLetter(),country, length,passWord);
         }
	
    	else if (wrong==6)
         { //Game Over .
         cout<<endl
         <<setw(50)<<"+---------------------------------+\n"
         <<setw(50)<<"|               |                 |\n"
         <<setw(50)<<"|               |                 |\n"
         <<setw(50)<<"|                                 |\n"
         <<setw(50)<<"|                                 |\n"
         <<setw(50)<<"|    |                       \\    |\n"
         <<setw(50)<<"|               O                 |\n"
         <<setw(50)<<"|         +==========+            |\n"
         <<setw(50)<<"|  \\  /  |          |   /    |    |\n"
         <<setw(50)<<"+---------------------------------+\n"
		 <<setw(50)<<"|           You Dead              |\n"
         <<setw(50)<<"+---------------------------------+\n"
         <<setw(36)<< "Game Over"<<endl;
               cout<<setw(5)<<" "<<"the country was "<<country;
                 --score;
               cout<<endl<<setw(5)<<" "<<"=>your score : "<<score<<" points"<<endl
                   <<setw(5)<<" "<<"=>You entered "<<wrong<<" wrong letter in this country name so you dead.\n"
                   <<setw(5)<<" "<<"Continue playing to increase your score .\n"
                   <<setw(5)<<" "<<"if you want to try playing again enter 'Y' or 'y'\n"
			       <<setw(5)<<" "<<"if don't enter 'N' or 'n' .\n";
			   cin>>Continue;
			     if (Continue == 'Y' || Continue=='y' )
                    {cout<<setw(5)<<" "<<"Let's continue playing...\n";
					   startGame (score,wrong);}
  	                 else 
  	                 exit(0);
         }
	 }
}
//--------------------------------*finished ^_^ *------------------------------------