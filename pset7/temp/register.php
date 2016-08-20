  <?php

// configuration
require("../includes/config.php");

// if user reached page via GET (as by clicking a link or via redirect)
if ($_SERVER["REQUEST_METHOD"] == "GET")
{
    // else render form
    render("register_form.php", ["title" => "Register"]);
}

// else if user reached page via POST (as by submitting a form via POST)
else if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    // TODO
if(empty($_POST["username"]))
{
    apologize("Bad user name.");
}
if(empty($_POST["password"]) || empty($_POST["confirmation"]))
{
    apologize("Bad password");
}   
if($_POST["password"] != $_POST["confirmation"])
{
    apologize("passwords doesn't match");
}
else
{
    $reslt = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
    if($reslt === true)
    {
        apologize("User exists");
    }
    else
    {
        $result = CS50::query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000)", $_POST["username"], crypt($_POST["password"]));
        $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"];
         redirect("index.php");
    }
}
}