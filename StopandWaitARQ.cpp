
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n, frame;
    int lostFrame;

    cout << "Enter number of frames: ";
    cin >> n;

    // Generate a random frame number to be lost
    srand(time(0));
    lostFrame = rand() % n + 1;

    cout << endl <<    "Randomly selected lost frame: " << lostFrame << endl;

    for (frame = 1; frame <= n; frame++)
    {
        cout << endl <<"Sender: Sending Frame " << frame << endl;

        // Simulate random frame loss
        if (frame == lostFrame)
        {
            cout << "Receiver: Frame " << frame << " lost!" << endl;
            cout << "Sender: Waiting for ACK..." << endl;
            cout << "Sender: Timeout!" << endl;

            // Retransmission
            cout << "Sender: Retransmitting Frame " << frame << endl;
            cout << "Receiver: Frame " << frame << " received." << endl;
        }
        else
        {
            cout << "Receiver: Frame " << frame << " received." << endl;
        }

        cout << "Receiver: Sending ACK for Frame " << frame << endl;
        cout << "Sender: ACK received for Frame " << frame << endl;
    }

    cout << endl <<"All frames transmitted successfully." << endl;

    return 0;
}


/* Enter number of frames: 7

Randomly selected lost frame: 4

Sender: Sending Frame 1
Receiver: Frame 1 received.
Receiver: Sending ACK for Frame 1
Sender: ACK received for Frame 1

Sender: Sending Frame 2
Receiver: Frame 2 received.
Receiver: Sending ACK for Frame 2
Sender: ACK received for Frame 2

Sender: Sending Frame 3
Receiver: Frame 3 received.
Receiver: Sending ACK for Frame 3
Sender: ACK received for Frame 3

Sender: Sending Frame 4
Receiver: Frame 4 lost!
Sender: Waiting for ACK...
Sender: Timeout!
Sender: Retransmitting Frame 4
Receiver: Frame 4 received.
Receiver: Sending ACK for Frame 4
Sender: ACK received for Frame 4

Sender: Sending Frame 5
Receiver: Frame 5 received.
Receiver: Sending ACK for Frame 5
Sender: ACK received for Frame 5

Sender: Sending Frame 6
Receiver: Frame 6 received.
Receiver: Sending ACK for Frame 6
Sender: ACK received for Frame 6

Sender: Sending Frame 7
Receiver: Frame 7 received.
Receiver: Sending ACK for Frame 7
Sender: ACK received for Frame 7

All frames transmitted successfully.*/