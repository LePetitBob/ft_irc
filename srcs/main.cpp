#include "ft_irc.hpp"

int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Surveiller stdin (fd 0) en attente d'entrées */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /* Pendant 5 secondes maxi */
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Considérer tv comme indéfini maintenant ! */

    if (retval == -1)
        std::cerr << "select()" << std::endl;
    else if (retval)
        std::cout << "Des données sont disponibles maintenant\n" << std::endl;
        /* FD_ISSET(0, &rfds) est vrai */
    else
        std::cout << "Aucune données durant les 5 secondes\n" << std::endl;
    return (0);
}