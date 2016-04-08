ConnectX Bug Report
---------

### Total tests performed: 9
### 6 PASSED and 3 FAILED


Failed tests
---------
1. **Accessing element which is out of bound**
 * **Function:** ConnectX::at(int, int)
 * **Reason:** at() function fails to return INVALID when given out of bound indexes.
	The actual issue is in inBounds() function which at() uses for validation. Irrespective of whatever WIDTH you pass, inBounds() will return true if your HEIGHT is in valid range.
 * **Faulty Code Stub:** In ConnectX.cpp


            Piece ConnectX::at(int w, int h)
            {
	             if( inBounds(w,h) )  // Call to inBound()
	             {
	                return board[h][w];
	             }
	             ...
	             ...
	          }

2. **Constructor sets default values to all 3 variables even if any one of them is invalid**
 * **Function:** ConnectX::ConnectX(int, int, int)
 * **Expected:** Constructor should pick individual default values for unexpected inputs.
 * **Example:** If we pass positive values to *height* and *x* but negative value to *width*, constructor should only pick default value of *width* and use provided *height* and *x*. But here it sets default value to all three variables.
 * **Faulty Code Stub:** In ConnectX.cpp


            ConnectX::ConnectX(int wide, int high, int x)
            {   
	           //invalid input resets everything to default settings
	           if( wide <= 0 || high <= 0 || x <= 0)  // Logical error
	           {
		          wide=DEFAULT_WIDTH;
		          high=DEFAULT_HEIGHT;
		          x=DEFAULT_TO_WIN;
	           }
                   ...
                   ...
            }

3. **Segmentation fault on providing negative parameter to placePiece() function**
 * **Function:** ConnectX::placePiece(int)
 * **Expected:** Do nothing. Or notify user about invalid position.
 * **Faulty Code Stub:** In ConnectX.cpp

            void ConnectX::placePiece(int column)
            {
               for(int i=height-1; i>=0; i--)
               {
                  if( at(column,i) == EMPTY && inBounds(column,i) ) // Accessing element without verifying column value.
                  {
                     ...
                     ...
                  }
               }
               ...
            }
