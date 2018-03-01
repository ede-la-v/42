<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
		<title>Connexion</title>
		<script src="connexion.js"></script>
	</head>

    <body >
        <div class="container">
			<?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/entete.php'); ?>



				<form  method="post" action="/Controleur/Connexion.php" class="row text-center navbar-form navbar-center inline-form">

						<div class="input-group">
                        <label for="pseudo">Pseudo :</label> <input type="text" name="pseudo" id="pseudo" class="input-sm form-control" required /><br />
						<label for="pass">Mot de passe :</label> <input type="password" name="pass" id="pass" class="input-sm form-control"  required /><br />
						<input type="submit" value="Connexion" name="Connexion" id='connexion_membre' class='btn btn-primary btn-sm'>
						<a href="/Vue/change_pass.php">MDP oublie</a>
                        </div>
                        
				</form>
				

            <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>


        </div>
    </body>
</html>
