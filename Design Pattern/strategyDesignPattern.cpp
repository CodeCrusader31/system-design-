#include<iostream>
using namespace std;


// strategy Interface for walk
class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {};
};


// concreate stretegy for walk

class NormalWalk : public WalkableRobot{
public:
    void walk() override{
        cout << "Walking Normally ..."<<endl;
    }
};

class Nowalk : public WalkableRobot{
public:
    void walk() override {
        cout << "Cannot Walk." << endl;
    }
};

// Strategy interface for walk
class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {};
};

class NormalTalk : public TalkableRobot{
public:
    void talk() override{
        cout << "Talking normally ..."<<endl;
    }
};

class NoTalk : public TalkableRobot{
public:
    void talk() override{
        cout << "No Talk " << endl;
    }
};

class FlyableRobot{
public:
    virtual void Fly() = 0;
    virtual ~FlyableRobot() {}; 
};

class NormalFly : public FlyableRobot{
public:
    void Fly() override{
        cout << "Flying normally ..."<<endl;
    }
};

class NoFly : public FlyableRobot{
public:
    void Fly() override{
        cout << "No Fly " << endl;
    }
};


// Robot Base class
class Robot{
protected:
    WalkableRobot*  walkBehaviour;
    TalkableRobot* TalkBehaviour;
    FlyableRobot* flyBehaviour;
public:
    Robot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f){
        this->walkBehaviour = w;
        this->TalkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        TalkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->Fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot{
public:
    CompanionRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):
    Robot(w,t,f){}

    void projection() override{
        cout << "Displaying Companion efficient stats..." << endl;
    }
};

class WorkerRobot : public Robot{
public:
    WorkerRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):
    Robot(w,t,f){}

    void projection() override{
        cout << "Displaying worker efficient stats..." << endl;
    }
};

// main function
int main(){
    Robot *robot1 = new CompanionRobot(new NormalWalk(),new NormalTalk(),new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "......................" << endl;


    Robot *robot2 = new WorkerRobot(new Nowalk(),new NoTalk(),new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    cout << "-----end ---------" ;
    return 0;

}
