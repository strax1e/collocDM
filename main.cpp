/* Main module
 * Authors:
 * - Afanasyev Andrey 9373
 * - Arutunyan Vladimir 9373
 * - Savinov Aleksey 9373
 * - Berezin Aleksandr 9373
 * - Tihonov Danil 9373
 * - Sidorov Egor 9373
 * - Kodukov Aleksandr 9373
 * - Emilia Shmidt 9373
 */

#include "typedef.h"

using namespace poly;

int main( void )
{
  Polynom a(std::vector<float>{1, 2, 3}), b(std::vector<float>{3, 2, 1}), c = a + b;
  c = c + a + b;
  a += b += c;
  a = c;
  c.Print();
  
  return 30;
}