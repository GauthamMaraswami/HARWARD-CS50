<?php
    // configuration
    require("../includes/config.php"); 	
/*	 if ($_SERVER["REQUEST_METHOD"] !== "POST")
   {
    $id = $_SESSION["id"];
    // Retrieve all the shares this users owns
	$rows = CS50::query("SELECT id, symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
				
	// A positions array which stores all the information about the shares
	$positions = [];
	foreach ($rows as $row)
	{
	  $stock = lookup($row["symbol"]);
	  if ($stock !== false)
	  {
		  $positions[] = [
		  
		  "symbol" => $row["symbol"]
		  
		  ];
	  }
	}
	  
	// This is the balance of the user
	
    render("sell_form.php", ["title" => "Positions", "positions" => $positions]);
    }*/
    
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
{	
	// Check if the userinputted anything
	if(empty($_POST["stock"]))
	{
		apologize("You need to specify which stock to sell.");
	}else{
		$id = $_SESSION["id"];
		$stock = $_POST["stock"];
	// If the user doesn't own any of the stock, error message is displayed
	if(!$shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = $id AND symbol = '$stock'")){
		apologize("You don't own any shares of this stock");
	}else{
	 	$value = lookup("$stock");
	 	$shares = $shares[0]["shares"];
	 	$price = $value["price"];
	 	$profit = $shares*$price;
	 	
	 	// Delete the stock from the users portfolios and update the balance
	 	CS50::query("DELETE FROM portfolios WHERE user_id = $id AND symbol = '$stock'");
	 	CS50::query("UPDATE users SET cash = cash + $profit WHERE id = $id");
	    CS50::query("INSERT INTO history (user_id, symbol, status, shares, price) 
	 	VALUES($id, '$stock', 'SELL', $shares, $price)");	
	 	render("../templates/sell.php", ["title" => "Sell", "value" => $value , "profit" => $profit]);
	 }
	}
}
else
{
  // else render form
  render("sell_form.php", ["title" => "Sell"]);
}

    ?>