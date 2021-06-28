template <class S, class T> class Pair
{
private:
    S x;
    T y;
/* ... */
};
  
template <class S> class Element
{
private:
    S x;
/* ... */
};
  
int main ()
{
    Pair <Element<int>, Element<char>> p;
    return 0;
}