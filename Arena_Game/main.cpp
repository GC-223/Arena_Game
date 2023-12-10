//
//  main.cpp
//  Arena_Game
//
//  Created by Greyson Chavez on 12/7/23.
//

#include <array>
#include <iostream>
#include <string>


class Attacks
{
    
} ;



// separate class to deal with stats
struct Stats
{
public:
    enum Type
    {
        health,
        attack,
        defense,
        
        max_stats
    } ;
    
    
private:
    
    // hold the integer value of stats
    std::array< int, max_stats> m_statsArray ;
    
    
public:
    // constructor
    Stats ( const std::array< int, max_stats>& stats)
    : m_statsArray { stats }
    {
    }
    

    
    // lets overload the subscript operator - this basically will now work as a getter for every numeric stat value
    int& operator[]( int index )
    {
        return m_statsArray[ index ] ;
    }
    
    
    // a function to get statName as a string
    std::string getNameAsString( Type type )
    {
        switch (type) {
            case health:
                return "Health" ;
            case attack:
                return "Attack";
            case defense:
                return "Defense" ;
            default:
                std::cout << "Error! invalid Stat Type!" ;
                return "Invalid";
        }
    }
    
} ;



class Gladiator
{
private:
    
    Stats m_stats ;
    
    
    std::string m_name { } ;
    
    Attacks attack { } ;
    
public:
    // going to want a constructor to initialize name and stats
    Gladiator( std::string_view name, const std::array< int, Stats::max_stats>& stats)
    : m_name { name }
    , m_stats { stats }
    {
    }
    
    
    // lets overload output real quick to see if it prints everything i want
    friend std::ostream& operator<<( std::ostream& out, Gladiator& g )
    {
        out << g.m_name << '\n' ;
        
        for ( int i = Stats::health ; i < Stats::max_stats ; ++i )
        {
            
            out << g.m_stats.getNameAsString( static_cast<Stats::Type>(i) ) << ": " <<  g.m_stats[ i ] << '\n' ;
        }
        
        return out ;
    }
   
    
    // getters
    // getter for an individual stat
    
    
    
    const std::string& getName() const
    {
        return m_name ;
    }
    
} ;




int main(int argc, const char * argv[]) {
    
    
    
    Gladiator greyson { "Greyson", { 1, 2, 3 } } ;
    
    std::cout << greyson << '\n' ;
    
        
//    std::cout << "Name: " << greyson.getName() << "\t\tHealth: " << greyson.getStat( health ) << '\n' ;
    
//    std::cout << greyson.getName() << "\t\tStats: " << greyson.getStats() << '\n' ;

    return 0;
}
