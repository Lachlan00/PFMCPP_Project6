/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {} //1
    int value;//2
    std::string name;//3
};

struct TFun                                //4
{
    T* compare(T* a, T* b) //5
    {   
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float v1 { 0 }, v2 { 0 };
    float funA(float& updatedValue)      //12
    {
        std::cout << "U's v1 value: " << v1 << std::endl;
        v1 = updatedValue;
        std::cout << "U's v1 updated value: " << v1 << std::endl;
        while(std::abs(v2 - v1) > 0.001f)
        {
            v2 += 0.1f;
        }
        std::cout << "U's v2 updated value: " << v2 << std::endl;
        return v2 * v1;
    }
};

struct UFun
{
    static float funA(U& that, float& updatedValue)        //10
    {
        std::cout << "U's v1 value: " << that.v1 << std::endl;
        that.v1 = updatedValue;
        std::cout << "U's v1 updated value: " << that.v1 << std::endl;
        while(std::abs(that.v2 - that.v1) > 0.001f)
        {
            that.v2 += 0.1f;
        }
        std::cout << "U's v2 updated value: " << that.v2 << std::endl;
        return that.v2 * that.v1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(29, "t1");                                             //6
    T t2(42, "t2");                                             //6
    
    TFun f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    std::cout << "the smaller one is << " << (smaller != nullptr ? smaller->name: "..well actually, they are the same..") << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << UFun::funA(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.funA(updatedValue) << std::endl;
}

        
