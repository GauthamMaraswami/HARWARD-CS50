<!--<div>
<form action="sell.php" method="post">
<fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
                <option value=""> </option>
     
    <body>
		<?php
		
			/*foreach ($positions as $position)
			{	  
			    print("hello");
				 print("<option value='{$position["symbol"]}'>{$position["symbol"]}</option>\n");
				print("<td>" . $position["symbol"] . "</td>");
				
			}*/
		?>
		 

    <body>
	
	</form>
	 </select>
            
            <br/>
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</div>
-->
<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="stock" placeholder="Stock" type="text"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>
