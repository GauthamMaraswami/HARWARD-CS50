<?php
    // configuration
    require("../includes/config.php"); 
	
	$id = $_SESSION["id"];
	
	// Retrieves all the transactions from the database ordered by date
	$history = CS50::query("SELECT symbol, status, shares, price, date FROM history WHERE user_id = $id ORDER BY date DESC");
	
    // render portfolio
    render("history_form.php", ["title" => "History", "history" => $history]);
?>