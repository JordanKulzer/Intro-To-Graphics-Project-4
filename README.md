# HW4
This is the fourth homework for COSC 4370


Jordan Kulzer PSID: 1863479


Environment: I built this project using Microsoft Visual Studio 2019.  I could not include all of the files, but I included my code and the image created. Let me know please if it is not enough or not running for you.


# Problem 1
To me, just getting started on this was the hardest part of the project. I had no idea how to utilize eigen values to create a shape.  Originally, I tried creating a cylinder, but a triangle turned out much easier. I knew I had to create a .h and .cpp file for it, and once I had that, I came across a reference that helped me complete it.  I did have some fun in the main.cpp file playing around with the different x's, y's, and z's.  For a while, my triangle was stuck in the upper right hand corner, until I used negative values in my pV[0] and pV[1], which adjusted my x and y values.  All I was really going for was creating a triangle that spanned across the front of the original spheres in order to show shadows and phong correctly.


# Problem 2
This one took me a little while to figure out.  I knew I didn't have to create a .frag and .vs, but wasn't sure how to implement it.  Then I thought of creating a function in scene.cpp specifically for phong, use eigen value Vector3d, and more or less copied my .frag from hw3 and re-used it.  I had to make tons of adjustments, but the core is very similar. I also really enjoyed creating color for the shapes. I had to add to the struct in the sphere.cpp and shape.h in order to change the color of the spheres though.  It's fun to trial and error different numbers to find different results.


# Problem 3
This one wasn't too bad, especially with the gitHub reference I found. But as with my phong function, my trace function used some parts from my .frag from hw3, which was mainly the creating lightDirection from lightPosition and the normal position.


# Problem 4
I couldn't figure this one out at all.  I spent hours scouring the internet trying to find out how to implement it in VS, but I couldn't do it.  


I put the references that I used at the top of the code in my file.
