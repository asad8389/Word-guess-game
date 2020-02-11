#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

void fill_ltr(string &guess , char ltr, string word);
int count=0;

int main()
{
    string word[]={ "india",
                    "bangladesh",
                    "australia",
                    "portugal",
                    "england",
                    "spain",
                    "germany",
                    "newzeland",
                    "austria",
                    "russia"
                    };
    char ltr;
    int i;


    srand(time(NULL));  //seed for random value
    int n= rand()%10;   //creating random value

    string guess=word[n];

    for(i=0;i<word[n].length();i++)
        guess[i]='*';                       //hiding the value

    cout<<"\t\t\t\tWelcome to the wordguess game, it's very simple "<<endl;
    cout<<"\t\t\t\t  You have 5 tries to guess the complete word\n\n"<<endl;

    for(;;)
    {
        //count to keep track on 5 chances
        count++;
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Your word is:  ";
        cout<<guess<<endl<<endl;

        cout<<"Enter your guess (only one letter):  ";
        cin>>ltr;

        fill_ltr(guess, ltr, word[n]);

        cout<<guess<<endl<<endl;

        //checking if word is complete
        if(guess==word[n]){
            cout<<"Congrats you guessed it correctly"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
            break;
            }

        //tries left
        cout<<"Tries left: "<<5-count<<endl;


        //for 5 tries
        if(count==5){
            cout<<"Oops your word is  : "<<word[n]<<endl<<"You loose "<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
            break;
            }


        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        system("pause");
        system("cls");


    }





}
void fill_ltr(string &guess, char ltr, string word)
{
    int i,k=0;

    for(i=0;i<guess.length();i++)
    {
        if(ltr==word[i]){
            k++;                        //for keep count on repeated values
            guess[i]= word[i];
            count--;
            if(k>1)
            count++;
        }
    }
}
