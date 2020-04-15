/* Natural numbers source code module
 * Authors:
 * - Afanasyev Andrey 9373
 * - Arutiunian Vladimir 9373
 */
#include <vector>
#include <string>
#include <assert.h>
#include <iostream>

namespace bign
{
    class BigNatural
    {
    private:
        std::vector<int> nums;
        friend BigNatural &operator+= ( BigNatural& left, const BigNatural& right );
        friend BigNatural &operator+= ( BigNatural& left, const long long &right );
        friend BigNatural &operator*= ( BigNatural& left, const BigNatural& right );
        friend const BigNatural operator+ ( const BigNatural& left, const BigNatural& right ); //2 перегрузки надо
        friend std::ostream& operator<< ( std::ostream& out, const BigNatural &obj );
    public:
        BigNatural( const std::string& inum );
        BigNatural( long long inum );
        BigNatural( const BigNatural& inum );
        ~BigNatural( void );
    };
    //std::ostream &operator<<(std::ostream &out, const BigNatural &obj)
} // namespace bign