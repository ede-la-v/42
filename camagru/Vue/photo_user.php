<?php
session_start();
if (!isset($_SESSION["id"]))
		header("Location: /index.php?error=log");

?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <link rel="stylesheet" type="text/css" href="index.css">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="/bootstrap/css/bootstrap.min.css" rel="stylesheet">
        <script src="index.js"></script>
        <title>Fotooos</title>
    </head>

    <body style="background-color: #f9f9f9;">
        <div class="container">
         <?php include($_SERVER['CONTEXT_DOCUMENT_ROOT']."/Vue/entete.php"); ?>
         <div id="comm" class=' hide'>
             <div id="comm_span"><span ></span></div>
             <hr>
             <input type="text" id="new_comm" />
         </div>
		<div class="row">
           
            
          <?php  
		    Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
            Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/display_photo_user.php');
			echo "<div class='row'>";
			$i = 1;
			foreach ($resultat as $photo) {
                if ($photo['id'] == $min["min"])
                    $max = 1;
				Include($_SERVER['DOCUMENT_ROOT'].'/Modele/get_like.php');
                if (isset($_SESSION["id"]))  
				    Include($_SERVER['DOCUMENT_ROOT'].'/Modele/get_like_user.php');
				echo "<div class='col-xs-12 col-sm-6 col-md-3'><img src='/images/".$photo['id'].".png' class='img-fluid img-thumbnail'></img><span class='like' data=".$photo['id'].">".$like_count[0];
				if (isset($_SESSION["id"]))
                {
                    if ($like_user)
    					echo "-";
    				else
    					echo "+";
                }
				echo "</span><span class='comm' data=".$photo['id'].">Commenter</span><a href='/Controleur/photo_user.php?page=";
                if (isset($_GET["page"])) 
                    echo htmlspecialchars($_GET["page"]);
                echo "&photo=".$photo['id']."'><img src=\"https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTbtvp-g3J-ZXI0VJ7GkAn36WvMzihagk4Co0s0s3B_Wi0D9LlpKQ\" class=\"delete\" /></a></div>";
				if ($i % 4 == 0)
					echo "</div><div class='row'>";
				$i++;
			}
			if ($i == 1)
				$max = 1;
			echo "</div>";

        ?>
		</div>
        <div class="row pager">
            <a href="/Vue/photo_user.php?page=<?php 
            if (isset($_GET['page']))
                echo htmlspecialchars($_GET['page']) - 1;
            ?>" class="<?php 
            if (!isset($_GET['page']) || $_GET['page'] == 1)
                echo "hide";
            ?>">Precedent</a>
            <a href="/Vue/photo_user.php?page=<?php 
            if (isset($_GET['page']))
                echo htmlspecialchars($_GET['page']) + 1;
            else
                echo 2;
            ?>" class="<?php 
            if (isset($max))
                echo "hide";
            ?>">Suivant</a>
        </div>
            <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>
		</div>
		
    </body>
</html>
