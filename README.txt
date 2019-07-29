Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Anisotropy Tutorial!
Prerequesites: Inheritence

In the previous example, "Character" was the "parent" class,
and "Necromancer", "Fighter" (etc), were the "child" clsases.

Virtual functions can be put in a parent class, which lets
them get overridden by a child class. By default, if a function
exists in both parent and child class, they will both be called,
but by making a function virtual, the child will override the parent,
but only if the child has a function to replace it. Otherwise, the 
virtual will be inherited and called by the child.
