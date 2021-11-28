<h3>The Key Calculation Process :</h3>

The Program Work By Calculating a Decryption Key For The Target File Based On Another File To Reproduce Again The Target File By Using The Key + The File Used in Key Calculation.
It Is Used To Share Data In a Secure Way, Out Of Sight, Invisible To Others, Like Sharing a file containing <b>Hello World</b>, But When You Decrypt this file with your key, You'll Obtain <b>F**k You</b> As An Example.

<h3>Usage: </h3>
  <ol>
    <li>make</li>
    <li>aix -h</li>
  </ol>
  <h5> Example: </h5>
   aix passwords.txt --keygen -f picture.jpg -k key.txt    (This will calculate a key for the passwords.txt and the picture.jpg files)
   aix passwords.txt --produce -f picture.jpg -k key.txt   (This will Reproduce the password.txt file by decrypting the picture.jpg file with the pre-calculated key.txt file)


<img src=AixCrypt-fcnt.png> </img>
