<?php
session_start();
if (!isset($_SESSION["id"]))
	header("Location: /index.php?error=log");
Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_mess_comm.php');
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
		<script src="change_user.js"></script>		
        <title>Change</title>
	</head>

    <body >
		<div class="container">
            <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/entete.php'); ?>
			

			
				<form  method="post" action="/Controleur/change_user.php" class="row text-center navbar-form navbar-center ">
				
						<div class="input-group">
						<label for="pseudo">Nouveau pseudo :</label> <input type="text" name="pseudo" id="pseudo"  class="input-sm form-control" /><br />
						<span>ET/OU</span>
						<label for="mail">Nouvel email</label> <input type="email" name="mail" id="mail" class="input-sm form-control" /><br />
						<span>ET/OU</span>
						<label for="npass">Nouveau MDP</label> <input type="password" name="npass" id="npass" class="input-sm form-control" /><br />
						<span>ET/OU</span>
						<div class="form-check text-center"><label class="form-check-label" for="mail"> Recevoir un message pour chaque nouveau commentaires?  </label><input class="form-check-input" type="checkbox" <?php if ($mess[0]) echo "checked='checked'"; ?>" class="input-sm form-control" name="mess"></div> 
						<label for="pass">entrez votre MDP pour confirmer les changements</label> <input type="password" name="pass" id="pass" class="input-sm form-control" required /><br />
						<input type="submit" value="Changer" name="Changer" class='btn btn-primary btn-sm'>
						</div>
				
				</form>
				
			<?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>	
			
		</div>
    </body>
</html>
