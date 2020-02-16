Write a program that simulates a checkout line at a supermarket. The line is a queue object. Customers (i.e. customer objects) arrive in random integer intervals of 1-4 minutes, also, each customer is served in random integers intervals of 1-4 minutes. Obviously, the rates need to be balanced. If the average arrival rate is larger than the average service rate, the queue will grow infinitely. Even with balanced rates, randomness can still cause long lines. Run the supermarket simulation for a 2-hour period (120 minutes) using the following algorithm:

1. Choose a random integer from 1 to 4 to determine the minute at which the first customer arrives
2. At the first customer’s arrival time:
  - Determine customer’s service time
  - Begin servicing the customer;
  - Schedule arrival time of next customers
3. For each minute of the day
 - If the next customer arrives, Say so, enqueue the customer, and schedule the arrival time of   the next customer.
 - If the services was completed for the last customer, Say so, dequeue next customer to be serviced and determined customer’s service completion time (random integer 1 – 4 added to the current time).

Now run your simulation for 120 minutes, and answer each of the following:

- What is the maximum number of customers in the queue at any time?
- What is the longest wait any one customer experiences?
- What happens if the arrival interval is changed from 1-4 minutes to 1-3 minutes?
