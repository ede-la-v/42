<?php
session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
        <title>Change</title>
	</head>

    <body >
		<div class="container">
            <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/entete.php'); ?>
			

				<form  method="post" action="/Controleur/change_pass_user.php?log=<?php echo $pseudo ?>" class="row text-center navbar-form navbar-center">
				    <div class="input-group">
						<label for="pass">Nouveau MDP</label> <input type="password" name="pass" id="pass" class="input-sm form-control" /><br />
						<label for="vpass">Verification MDP</label> <input type="password" name="vpass" id="pass2" class="input-sm form-control" /><br />
						<input type="submit" value="Changer" name="Changer" class='btn btn-primary btn-sm'>
				    </div>
				</form>
			 <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>
				
		</div>
    </body>
</html>
