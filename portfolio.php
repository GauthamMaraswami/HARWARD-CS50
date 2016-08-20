<!-- This displays a message with your current balance, and a table with your current shares -->
<div>

 <table class="table table-striped">
     
    <tbody>
		<?php
			print("<tr>");
				print("<th>Symbol</th>");
				print("<th>Name</th>");
				print("<th>Shares</th>");
				print("<th>Price</th>");
				print("<th>Total value</th>");
			print("</tr>");
				  
			foreach ($positions as $position)
			{	  
			    print("hello");
				print("<tr>");
				print("<td>" . $position["symbol"] . "</td>");
				print("<td>" . $position["name"] . "</td>");
				print("<td>" . $position["shares"] . "</td>");
				print("<td>" . $position["price"] . "</td>");
				print("<td>" . $position["total"] . "</td>");
				print("</tr>");
			}
		?>
		 <tr>
       
        	<div id="message">
		<?php
			print("Hello, ". $cash[0]["username"] .". Your current balance is " . sprintf("%.2f",$cash[0]["CASH"]).".");
		?>
	</div>
    </tr>

    </tbody>
	</table>
</div>