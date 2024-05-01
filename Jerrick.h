#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Actor {

protected:

   int atk = 0;
   int Hp = 0;
   bool isalive = false;

public:

   virtual ~Actor() = default;
   
   int set_Atk (const int &new_Atk) {
       atk = new_Atk;
   }
   
   int get_Atk() const {return atk; }

   int set_Hp (const int &new_Hp) {
       Hp = new_Hp;
   }
   
   int get_Hp() const {return Hp; }

   bool get_isalive() const {return isalive;}

   void set_isalive(const bool &new_isalive) {
       isalive = new_isalive;
   }
 };

   class Hero : public Actor {
     protected:
   };

   class JohnAnglin : public Hero {
   public:
        int Shiv_stab();
        int headbutt();
   };

   class ClarenceAnglin : public Hero {
   public:
        int Shiv_stab();
        int headbutt();
   };

   class Inmate : public Actor {
     protected :
   };

   class AlCapone : public Inmate {
     public:
         int Soups_thief();
   };

   class GeorgeKelly : public Inmate{
     public:
        int Soap_drop();
   };
   class AlvinKarpis : public Inmate {
     public:
        int SoupSlap();
   };
   class ArthurBarker : public Inmate {
     public:
        int SpoonStab();
   };
   class RobertStroud : public Inmate {
     public:
        int RightHook();
   };
   class JoeBowers : public Inmate {
    public:
        int Dropkick();
   };
   class HenryYoung : public Inmate {
    public:
        int LeftHook();
   };



