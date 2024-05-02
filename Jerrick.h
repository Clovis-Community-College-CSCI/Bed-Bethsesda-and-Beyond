#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

class Actor {

protected:

   int atk = 0;
   int Hp = 0;
   bool isalive = false;

public:

   virtual ~Actor() = default;
   
   void  set_Atk (const int &new_Atk) {
       atk = new_Atk;
   }
   
   int get_Atk() const {return atk; }

   void set_Hp (const int &new_Hp) {
       Hp = new_Hp;
		if (Hp <=0) {
		   Hp = 0;
		   isalive = false;//Set "isalive" to false if HP drops to 0
		}
   }
   
   int get_Hp() const {return Hp; }

   bool get_isalive() const {return isalive;}

   void set_isalive(const bool &new_isalive) {
       isalive = new_isalive;
   }

   virtual void AI() = 0; //Pure virtual for AI
 };

   class Hero : public Actor {
     protected:
   };

   class JohnAnglin : public Hero {
   public:
	   JohnAnglin() {
	     set_Hp(100);//Setting Hp
	     set_Atk(20);//Setting Atk
	   }
        void Shiv_stab() {
	      cout << "John Anglin used Shiv stab!"<< endl;
	    }
        void headbutt() {
	      cout << "John Anglin used headbutt!"<< endl;
	    }
	    void AI() override {
	       return;
	    }
   };

   class ClarenceAnglin : public Hero {
   public:
	    ClarenceAnglin() {
	      set_Hp(120); //Setting Hp
          set_Atk(25); //Setting Atk
	    }

        void Shiv_stab() {
	cout << "Clarence used Shiv stab!" << endl;
	}
        void headbutt() {
	cout << "Clarence used headbutt!" << endl;
	}
	    void AI() override {
	      return;
	}
   };

   class Inmate : public Actor {
     protected :
	    virtual void AI() override {
	//AI function for Inmates/Guards to wander the map
	//A message for indicating movement
	cout << "Inmate is wandering around the cell block." << endl;
	}
   };

   class Guard  : public Inmate {
     public:
       Guard() {
         set_Hp(150);
         set_Atk(10);
       }
       void AI() override {
        cout << "Guard is patrolling the area." << endl;
       }
   };

   class AlCapone : public Inmate {
     public:
	   AlCapone() {
	     set_Hp(150);
	     set_Atk(20);
	   }
       void Soups_thief() {
	    cout << "Al Capone steals soups!" << endl;
	   }
   };

   class GeorgeKelly : public Inmate{
     public:
	   GeorgeKelly() {
	      set_Hp(100);
	      set_Atk(30);
	   }

       void Soap_drop(){
	   cout << "George Kelly drops the soap." << endl;
	   }
   };
   class AlvinKarpis : public Inmate {
     public:
	    AlvinKarpis() {
	      set_Hp(150);
	      set_Atk(50);
	    }
        void SoupSlap() {
	    cout << "Alvin Karpis slaps your soup." << endl;
	}
   };
   class ArthurBarker : public Inmate {
     public:
	    ArthurBarker() {
	      set_Hp(80);
	      set_Atk(150);
	    }

        void SpoonStab() {
	    cout << "Arthut Barker stabs you with a spoon." << endl;
	    }
   };
   class RobertStroud : public Inmate {
     public:
	    RobertStroud() {
	       set_Hp(110);
	       set_Atk(90);
	    }
        void RightHook() {
	    cout << "Robert Stroud hits you with a right hook." << endl;
	    }
   };
   class JoeBowers : public Inmate {
    public:
	    JoeBowers() {
	      set_Hp(90);
	      set_Atk(175);
	    }
        void Dropkick() {
	     cout << "Joe Bowers dropkicks you." << endl;
	    }
   };
   class HenryYoung : public Inmate {
    public:
	    HenryYoung() {
	      set_Hp(120);
	      set_Atk(90);
	    }

        void LeftHook() {
	    cout << "Henry Young hits you with a left hook." << endl;
	    }
   };

int main() {
     //Shared pointers for Heroes
    std::shared_ptr<JohnAnglin> john = std:: make_shared<JohnAnglin>();
    std::shared_ptr<ClarenceAnglin> clarence = std::make_shared<ClarenceAnglin>();

    //Shared pointers for Guards
    std::shared_ptr<Guard> guard1 = std::make_shared<Guard>();
    std::shared_ptr<Guard> guard2 = std::make_shared<Guard>();
    std::shared_ptr<Guard> guard3 = std::make_shared<Guard>();
    std::shared_ptr<Guard> guard4 = std::make_shared<Guard>();

    //Shared pointers for Inmates
    std::shared_ptr<AlCapone> al = std::make_shared<AlCapone>();
    std::shared_ptr<GeorgeKelly> george = std::make_shared<GeorgeKelly>();
    std::shared_ptr<AlvinKarpis> alvin = std::make_shared<AlvinKarpis>();
    std::shared_ptr<ArthurBarker> arthur = std::make_shared<ArthurBarker>();
    std::shared_ptr<RobertStroud> robert = std::make_shared<RobertStroud>();
    std::shared_ptr<JoeBowers> joe = std::make_shared<JoeBowers>();
    std::shared_ptr<HenryYoung> henry = std::make_shared<HenryYoung>();

    //vector of shared pointers for the actors 
    std::vector<std::shared_ptr<Actor>> actors;

    // Add actors to vector
    actors.push_back(john);
    actors.push_back(clarence);
    
    // Add guards to the vector
    actors.push_back(guard1);
    actors.push_back(guard2);
    actors.push_back(guard3);
    actors.push_back(guard4);

    //Add Inmates to the vector
    actors.push_back(al);
    actors.push_back(george);
    actors.push_back(alvin);
    actors.push_back(arthur);
    actors.push_back(robert);
    actors.push_back(joe);
    actors.push_back(henry);

    // Game loop
     while (true) {
      //The AI for each of the actors
        for (const auto& actor : actors) {
			 actor->AI();
		}
        // Check for any dead actors
        for (const auto& actor : actors) {
			 if (!actor->get_isalive()) {
			 cout << "Actor is dead." << endl;
			 }
        }

       //Simulating the game tick delay
       this_thread::sleep_for(chrono::milliseconds(1000)); // <- This can be adjusted
    }

  return 0;
}
    
    
    



