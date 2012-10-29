Cinder-Awesomium
================

Cinder block for the Awesomium web browser library.


Included is the Windows distribution of Awesomium 1.7.0 RC3, excluding their ```samples``` and ```wrappers``` folders.


To use this block with a release version of Cinder, clone the Cinder-Awesomium GIT repository to the ```cinder_master/blocks/awesomium``` folder.
* Open a command window
* Switch to the disk containing the Cinder root folder: ```d:```
* Browse to the Cinder root folder: ```cd path\to\cinder_master```
* Clone the repository: ```git clone https://github.com/paulhoux/Cinder-Awesomium.git blocks/awesomium```

Alternatively, you can download the repository as a [ZIP-file](https://github.com/paulhoux/Cinder-Awesomium/zipball/master) and manually add the files to a "cinder_master\blocks\awesomium" folder.

To use this block with a forked GIT version of Cinder, add the Cinder-Awesomium GIT repository as a submodule:
* Open a command window
* Switch to the disk containing the Cinder root folder: ```d:```
* Browse to the Cinder root folder: ```cd path\to\cinder_master```
* Add the Awesomium block: ```git submodule add https://github.com/paulhoux/Cinder-Awesomium.git blocks/awesomium```


To use the block in your project:
* Add the following folders to your include folders: 
** ```cinder_master\blocks```
** ```cinder_master\blocks\awesomium\include``` 
* Add the following folder to your library folders: ```cinder_master\blocks\awesomium\build\lib```
* Add the following .lib files to your dependencies: ```awesomium.lib```
* Add this include statement at the top of your .cpp files: ```#include "awesomium/CinderAwesomium.h"```
* Copy ALL files from ```cinder_master\blocks\awesomium\build\bin``` to your Debug and Release folders.



Please refer to the Awesomium license for more information on licensing fees. Awesomium is NOT free software!


Copyright (c) 2010-2012, Paul Houx - All rights reserved.
This code is intended for use with the Cinder C++ library: http://libcinder.org

Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and	the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
