#include <iostream>
#include <exception>
#include "ReplServer.h"
#include "common_factor.hpp"

const time_t secs_between_repl = 20;
const unsigned int max_servers = 10;

/*********************************************************************************************
 * ReplServer (constructor) - creates our ReplServer. Initializes:
 *
 *    verbosity - passes this value into QueueMgr and local, plus each connection
 *    _time_mult - how fast to run the simulation - 2.0 = 2x faster
 *    ip_addr - which ip address to bind the server to
 *    port - bind the server here
 *
 *********************************************************************************************/
// ReplServer::ReplServer(ip_addr("127.0.0.1"),_port(9999)) {
// }

ReplServer::ReplServer(/*DronePlotDB &plotdb, */const char *ip_addr, unsigned short port, unsigned long m)/*, float time_mult,
                                          unsigned int verbosity*/ 
   {
      num = m;
   }



/********************************************************************************************
 * modularPow - function to gradually calculate (x^n)%m to avoid overflow issues for
 *              very large non-prime numbers using the stl function pow (floats)
 *
 *    Params:  base - the base value x in the above function
 *             exponent - the exponent n
 *             modulus - the modulus m
 *
 *    Returns: resulting number
 ********************************************************************************************/

void math(unsigned long n) {

      std::cout << "Finding factors of " << n << std::endl;
      // unsigned long factor1 = calcPollardsRho(n);

      // std::cout << "Found factor: " << factor1 << std::endl;
}


unsigned long modularPow(unsigned long base, int exponent, unsigned long modulus) {
   unsigned long result = 1;

   while (exponent > 0) {

      // If the exponent is odd, calculate our results 
      if (exponent & 1) {
         result = (result * base) % modulus;
      }

      // exponent = exponent / 2 (rounded down)
      exponent = exponent >> 1;

      base = (base * base) % modulus;
   }
   return result;

}

/**********************************************************************************************
 * calcPollardsRho - Do the actual Pollards Rho calculations to attempt to find a divisor
 *
 *    Params:  n - the number to find a divisor within
 *    
 *    Returns: a divisor if found, otherwise n
 *
 *
 **********************************************************************************************/
unsigned long calcPollardsRho2(unsigned long n) {
   std::cout << "Yay!" << std::endl;
}


unsigned long calcPollardsRho(unsigned long n) {
   if (n <= 3)
      return n;

   // Initialize our random number generator
   srand(time(NULL));

   // pick a random number from the range [2, N)
   unsigned long x = (rand()%(n-2)) + 2;
   unsigned long y = x;    // Per the algorithm

   // random number for c = [1, N)
   unsigned long c = (rand()%(n-1)) + 1;

   unsigned long d = 1;

   // Loop until either we find the gcd or gcd = 1
   while (d == 1) {
      // "Tortoise move" - Update x to f(x) (modulo n)
      // f(x) = x^2 + c f
      x = (modularPow(x, 2, n) + c + n) % n;

      // "Hare move" - Update y to f(f(y)) (modulo n)
      y = (modularPow(y, 2, n) + c + n) % n;
      y = (modularPow(y, 2, n) + c + n) % n;

      // Calculate GCD of |x-y| and tn
      unsigned long z = /*(unsigned long)*/ x - /*(unsigned long)*/ y;
      if (z < 0)
         d = boost::math::gcd(/* (unsigned long) */ -z, /* (unsigned long) */ n);
      else
         d = boost::math::gcd(/* (unsigned long) */ z, /* (unsigned long) */ n);

      // If we found a divisor, factor primes out of each side of the divisor
      if ((d != 1) && (d != n)) {
         return /* (unsigned long) */ d;

      }

   }
   return /* (unsigned long) */ d;
}


void combinePrimes(std::list<unsigned long> &dest) {
   //dest.insert(dest.end(), primes.begin(), primes.end());
}

















 // :_queue(verbosity),
                                 //  _plotdb(plotdb),
                                 //  _shutdown(false), 
                                 //  _time_mult(time_mult), 
                                 //  _verbosity(verbosity),
                                 //  _ip_addr(ip_addr),
                                 //  _port(port)                                

// {
// }

ReplServer::~ReplServer() {

}


/**********************************************************************************************
 * getAdjustedTime - gets the time since the replication server started up in seconds, modified
 *                   by _time_mult to speed up or slow down
 **********************************************************************************************/

// time_t ReplServer::getAdjustedTime() {
//    return static_cast<time_t>((time(NULL) - _start_time) * _time_mult);
// }

/**********************************************************************************************
 * replicate - the main function managing replication activities. Manages the QueueMgr and reads
 *             from the queue, deconflicting entries and populating the DronePlotDB object with
 *             replicated plot points.
 *
 *    Params:  ip_addr - the local IP address to bind the listening socket
 *             port - the port to bind the listening socket
 *             
 *    Throws: socket_error for recoverable errors, runtime_error for unrecoverable types
 **********************************************************************************************/

void ReplServer::replicate(const char *ip_addr, unsigned short port) {
   _ip_addr = ip_addr;
   _port = port;
   replicate();
}

void ReplServer::replicate() {

   std::cout << "replicate test" << std::endl;
   // Track when we started the server
   // _start_time = time(NULL);
   // _last_repl = 0;

   // Set up our queue's listening socket
   // _queue.bindSvr(_ip_addr.c_str(), _port);
   // _queue.listenSvr();

   // if (_verbosity >= 2)
   //    std::cout << "Server bound to " << _ip_addr << ", port: " << _port << " and listening\n";

  
   // Replicate until we get the shutdown signal
   // while (!_shutdown) {

      // Check for new connections, process existing connections, and populate the queue as applicable
      // _queue.handleQueue();     

      // See if it's time to replicate and, if so, go through the database, identifying new plots
      // that have not been replicated yet and adding them to the queue for replication
      // if (getAdjustedTime() - _last_repl > secs_between_repl) {

      //    queueNewPlots();
      //    _last_repl = getAdjustedTime();
      // }
      
      // Check the queue for updates and pop them until the queue is empty. The pop command only returns
      // incoming replication information--outgoing replication in the queue gets turned into a TCPConn
      // object and automatically removed from the queue by pop
      // std::string sid;
      // std::vector<uint8_t> data;
      // while (_queue.pop(sid, data)) {

      //    // Incoming replication--add it to this server's local database
      //    addReplDronePlots(data);         
      // }       

      // usleep(1000);
   // }   
}

/**********************************************************************************************
 * queueNewPlots - looks at the database and grabs the new plots, marshalling them and
 *                 sending them to the queue manager
 *
 *    Returns: number of new plots sent to the QueueMgr
 *
 *    Throws: socket_error for recoverable errors, runtime_error for unrecoverable types
 **********************************************************************************************/

// unsigned int ReplServer::queueNewPlots() {
//    std::vector<uint8_t> marshall_data;
//    unsigned int count = 0;

//    if (_verbosity >= 3)
//       std::cout << "Replicating plots.\n";

//    // Loop through the drone plots, looking for new ones
//    std::list<DronePlot>::iterator dpit = _plotdb.begin();
//    for ( ; dpit != _plotdb.end(); dpit++) {

//       // If this is a new one, marshall it and clear the flag
//       if (dpit->isFlagSet(DBFLAG_NEW)) {
         
//          dpit->serialize(marshall_data);
//          dpit->clrFlags(DBFLAG_NEW);

//          count++;
//       }
//       if (marshall_data.size() % DronePlot::getDataSize() != 0)
//          throw std::runtime_error("Issue with marshalling!");

//    }
  
//    if (count == 0) {
//       if (_verbosity >= 3)
//          std::cout << "No new plots found to replicate.\n";

//       return 0;
//    }
 
//    // Add the count onto the front
//    if (_verbosity >= 3)
//       std::cout << "Adding in count: " << count << "\n";

//    uint8_t *ctptr_begin = (uint8_t *) &count;
//    marshall_data.insert(marshall_data.begin(), ctptr_begin, ctptr_begin+sizeof(unsigned int));

//    // Send to the queue manager
//    if (marshall_data.size() > 0) {
//       _queue.sendToAll(marshall_data);
//    }

//    if (_verbosity >= 2) 
//       std::cout << "Queued up " << count << " plots to be replicated.\n";

//    return count;
// }

/**********************************************************************************************
 * addReplDronePlots - Adds drone plots to the database from data that was replicated in. 
 *                     Deconflicts issues between plot points.
 * 
 * Params:  data - should start with the number of data points in a 32 bit unsigned integer, 
 *                 then a series of drone plot points
 *
 **********************************************************************************************/

// void ReplServer::addReplDronePlots(std::vector<uint8_t> &data) {
//    if (data.size() < 4) {
//       throw std::runtime_error("Not enough data passed into addReplDronePlots");
//    }

//    if ((data.size() - 4) % DronePlot::getDataSize() != 0) {
//       throw std::runtime_error("Data passed into addReplDronePlots was not the right multiple of DronePlot size");
//    }

//    // Get the number of plot points
//    unsigned int *numptr = (unsigned int *) data.data();
//    unsigned int count = *numptr;

//    // Store sub-vectors for efficiency
//    std::vector<uint8_t> plot;
//    auto dptr = data.begin() + sizeof(unsigned int);

//    for (unsigned int i=0; i<count; i++) {
//       plot.clear();
//       plot.assign(dptr, dptr + DronePlot::getDataSize());
//       addSingleDronePlot(plot);
//       dptr += DronePlot::getDataSize();      
//    }
//    if (_verbosity >= 2)
//       std::cout << "Replicated in " << count << " plots\n";   
// }


/**********************************************************************************************
 * addSingleDronePlot - Takes in binary serialized drone data and adds it to the database. 
 *
 **********************************************************************************************/

// void ReplServer::addSingleDronePlot(std::vector<uint8_t> &data) {
//    DronePlot tmp_plot;

//    tmp_plot.deserialize(data);

//    _plotdb.addPlot(tmp_plot.drone_id, tmp_plot.node_id, tmp_plot.timestamp, tmp_plot.latitude,
//                                                          tmp_plot.longitude, getAdjustedTime());
// }


// void ReplServer::shutdown() {
//    _shutdown = true;
// }
